#include "ezhno/AST/Decl.h"
#include "ezhno/AST/Function.h"
#include "ezhno/Parse/Parser.h"

namespace ezhno {

bool Parser::ParseFirstTopLevelDecl(DeclRef& Result) {
  Lxr.Lex(Tok);
  return ParseTopLevelDecl(Result);
}

bool Parser::ParseTopLevelDecl(DeclRef& Result) {
  switch (token.getKind) {
  default:
    break;
  case token::eof:
    return true;
  case token::int32:
    ParseFunctionDefinition(Result);
    return false;
  }
}

bool Parser::ParseFunctionDefinition(DeclRef& Result) {
  Type T (Type::KInt32);
  Result = static_cast<Decl*>(new Function(T, N, Args, B));
}

}
