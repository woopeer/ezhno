#include "ezhno/Parse/Parser.h"

namespace ezhno {

bool ParsePrimitiveExpression(Expr*& Result) {
}

bool ParseAdditiveExpression(Expr*& Result) {
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
