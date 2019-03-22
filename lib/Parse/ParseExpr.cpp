#include "ezhno/Parse/Parser.h"

namespace ezhno {

bool ParsePrimitiveExpression(Expr*& Result) {
}

bool Parser::ParseAdditiveExpression(Expr*& Result) {
  Expr* E;
  ParsePrimitiveExpression(E);
  while (Tok.is(token::pt_plus) || Tok.is(token::pt_minus)) {
  }
}

bool ParseAssignmentExpression(Expr*& Result) {
}

// expression ::
//   assignment-expression
//
// assignment-expression ::
//   additive-expression
//   identifier = expression
// 
// additive-expression ::
//   primitive-expresion
//   additive-expression + primitive-expression
//   additive-expression - primitive-expression
//
// primitive-expression ::
//   literal (int32)
//   identifier
bool Parser::ParseExpression(Expr*& Result) {
}

}
