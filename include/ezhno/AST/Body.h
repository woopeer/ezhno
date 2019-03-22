#ifndef EZHNO_AST_BODY_H
#define EZHNO_AST_BODY_H
namespace ezhno {

class Stmt;

class Body {
  Stmt* Stmts;
  unsigned LenOfStmts;
};

}
#endif /* EZHNO_AST_BODY_H */
