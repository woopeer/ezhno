#ifndef EZHNO_AST_STMT_H
#define EZHNO_AST_STMT_H
namespace ezhno {

class Stmt {
  enum Kind {
    KExpr,
    KAssignment
  };
  union {
    Expr& E;
    Assignment& Assign;
  };
};

}
#endif /* EZHNO_AST_STMT_H */
