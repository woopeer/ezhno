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
  Parser(Lexer& Lxr) : Lxr(Lxr) {}

  bool ParseFirstTopLevelDecl(DeclRef& Result);
  bool ParseTopLevelDecl(DeclRef& Result);

  bool ParseFunctionDefinition(DeclRef& Result);
  bool ParseFunctionArguments(Args& Result);
  bool ParseFunctionBody(Body& Result);

  bool ParseAssignmentStmt(Stmt& Result);
  bool ParseExprStmt(Stmt& Result);
  bool ParseReturn(Stmt& Result);

  bool ParseAdditionExpr(Expr& Result);
  bool ParseSubtractExpr(Expr& Result);
}

}

#endif /* EZHNO_PARSE_PARSER_H */
