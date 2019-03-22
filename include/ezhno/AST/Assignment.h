#ifndef EZHNO_AST_ASSIGNMENT_H
#define EZHNO_AST_ASSIGNMENT_H
namespace ezhno {

class Name;
class Expr;

class Assignment {
  Name& Nm;
  Expr& E;
};

}
#endif /* EZHNO_AST_ASSIGNMENT_H */
