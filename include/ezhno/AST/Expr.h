#ifndef EZHNO_AST_EXPR_H
#define EZHNO_AST_EXPR_H
namespace ezhno {

class Expr {
  enum Kind {
    KPlus,
    KMinus,
    KUnary
  };
  class Operator {
  };
  Value& V;
  Operator& Op;
  Expr* E; // E should be nullptr if Op is unary operator
};

}
#endif /* EZHNO_AST_EXPR_H */
