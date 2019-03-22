#include "ezhno/Lex/Token.h"
#include "ezhno/Lex/Lexer.h"
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
  do {
    TokPtr = new Token;
    Token& token = *TokPtr;
    tokens.insert(TokPtr);
    lexer.Lex(token);
    if (token.getKind() != token::eof) {
      std::cout << token.toString() << ' ';
      std::cout << '[' << unsigned(token.getKind()) << ']';
      if (token.getKind() == token::identifier)
        {
          std::cout << ": " << token.getLength();
          std::cout << " - " << long(token.getData());
        }
      else if (token.getKind() == token::value)
        {
          int i;
          llvm::StringRef(
              (char*)token.getData(), token.getLength()
            ).getAsInteger(10, i);
          std::cout << ": " << i;
        }
      std::cout << std::endl;
    }
  } while (TokPtr->getKind() != token::eof);
  
  std::cout << "total number of tokens : " << tokens.size() << std::endl;
  return 0;
}
