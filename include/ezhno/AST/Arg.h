#ifndef EZHNO_AST_ARG_H
#define EZHNO_AST_ARG_H
namespace ezhno {

class Type;
class Name;

class Arg {
  Type& Ty;
  Name& Nm;
};

}
#endif /* EZHNO_AST_ARG_H */
