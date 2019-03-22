#include "llvm/ADT/IntrusiveRefCntPtr.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/Option/OptTable.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/LangOptions.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticIDs.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Token.h"
#include "clang/Lex/Preprocessor.h"
#include "clang/Parse/Parser.h"
#include "clang/Parse/ParseAST.h"
#include "clang/Sema/Sema.h"
#include "clang/Sema/TemplateInstCallback.h"
#include "clang/Driver/Options.h"
#include "clang/Frontend/TextDiagnosticBuffer.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/CompilerInvocation.h"
#include <iostream>
#include <memory>

int
main (int argc_, char** argv_)
{
  llvm::SmallVector<const char *, 256> argv (argv_, argv_ + argc_);
  std::unique_ptr<clang::CompilerInstance> ego (new clang::CompilerInstance());
  clang::CompilerInstance& Ego = *ego.get();
  llvm::IntrusiveRefCntPtr<clang::DiagnosticIDs> DiagID (new clang::DiagnosticIDs);
  llvm::IntrusiveRefCntPtr<clang::DiagnosticOptions> DiagOpts = new clang::DiagnosticOptions;
  clang::TextDiagnosticBuffer *DiagsBuffer = new clang::TextDiagnosticBuffer;
  clang::DiagnosticsEngine Diags(DiagID, &*DiagOpts, DiagsBuffer);
  bool Success = clang::CompilerInvocation::CreateFromArgs(
      Ego.getInvocation(), argv.begin(), argv.end(), Diags);
  Ego.createDiagnostics();

  if (Ego.getFrontendOpts().ShowVersion) 
    {
      llvm::cl::PrintVersionMessage();
      return 0;
    }


  clang::FileManager *FileMgrPtr = Ego.createFileManager();
  Ego.createSourceManager(*FileMgrPtr);
  Ego.InitializeSourceManager(Ego.getFrontendOpts().Inputs[1]);
  Ego.getDiagnosticClient().BeginSourceFile(Ego.getLangOpts(), nullptr);
  
  Ego.setTarget(clang::TargetInfo::CreateTargetInfo(
        Ego.getDiagnostics(), Ego.getInvocation().TargetOpts));
  Ego.createPreprocessor(clang::TU_Complete);
  Ego.createASTContext();
  Ego.setASTConsumer(llvm::make_unique<clang::ASTConsumer>());
  Ego.createSema(clang::TU_Complete, nullptr);

  clang::Sema& S = Ego.getSema();

  clang::Preprocessor& PP = S.getPreprocessor();
  std::unique_ptr<clang::Parser> ParseOP (
      new clang::Parser(PP, S, Ego.getFrontendOpts().SkipFunctionBodies));
  clang::Parser& P = *ParseOP.get();

  clang::initialize(S.TemplateInstCallbacks, S);
  PP.getBuiltinInfo().initializeBuiltins(PP.getIdentifierTable(), PP.getLangOpts());
  PP.EnterMainSourceFile();
  P.Initialize();
  clang::Parser::DeclGroupPtrTy ADecl;
  unsigned NumOfTopLevelDecl = 0;
  for (bool AtEOF = P.ParseFirstTopLevelDecl(ADecl); !AtEOF;
       AtEOF = P.ParseTopLevelDecl(ADecl))
    {
      ++ NumOfTopLevelDecl;
    }
  clang::finalize(S.TemplateInstCallbacks, S);
  std::cout << "Found " << NumOfTopLevelDecl << " top level decls\n";
  
  return 0;
}
