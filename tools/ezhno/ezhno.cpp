#include "ezhno/Lex/Token.h"
#include "ezhno/Lex/Lexer.h"
#include "ezhno/Parse/Parser.h"
#include "llvm/ADT/DenseSet.h"
#include "llvm/ADT/StringRef.h"
#include <iostream>
#include <fstream>
using namespace ezhno;

int
main (int argc, char **argv)
{
  std::ifstream in(argv[1], std::ios::in);
  std::string contents;
  if (in){
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
  } else {
    std::cerr << "file doesn't exist." << "\n";
    std::exit(1);
  }

  Lexer lexer(contents);
  llvm::DenseSet<Token *> tokens;
  Token* TokPtr = nullptr;
  unsigned numUnkownTok = 0;
  do {
    TokPtr = new Token;
    Token& token = *TokPtr;
    tokens.insert(TokPtr);
    lexer.Lex(token);
    if (token.isNot(token::eof)) {
      std::cout << token.toString() << ' ';
      std::cout << '[' << unsigned(token.getKind()) << ']';
      if (token.getKind() == token::identifier) {
          std::cout << ": " << token.getLength();
      } else if (token.is(token::integer)) {
          int i;
          llvm::StringRef((char*)token.getData(), token.getLength()).getAsInteger(10, i);
          std::cout << ": " << i;
      } else if (token.is(token::unknown)) {
        ++ numUnkownTok;
      }
      std::cout << std::endl;
    }
  } while (TokPtr->isNot(token::eof));
  
  std::cout << "total # of tokens is " << tokens.size() << std::endl;
  std::cout << "total # of unknowns is " << numUnkownTok << std::endl;
  return 0;
}
