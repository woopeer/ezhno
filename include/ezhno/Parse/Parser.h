#ifndef EZHNO_PARSE_PARSER_H
#define EZHNO_PARSE_PARSER_H

#include "ezhno/Lex/Token.h"
#include "ezhno/Lex/Lexer.h"

namespace ezhno {

class Decl;
class Function;
class Arg;
class Body;
class Expr;

typedef Arg* Args;
typedef Decl* DeclRef;

class Parser {
  Lexer& Lxr;
  Token Tok;
public:
  Parser(Lexer& L) : Lxr(L) {}
 /*
  bool ParseFirstTopLevelDecl(DeclRef& Result);
  bool ParseTopLevelDecl(DeclRef& Result);

  bool ParseFunctionDeclaration(DeclRef& Result);
  bool ParseFunctionDefinition(DeclRef& Result);

  bool ParseStatement(Stmt*&);
  */
  bool ParseAdditiveExpression(Expr*&);
  bool ParseExpression(Expr*&);
};

}

#endif /* EZHNO_PARSE_PARSER_H */
