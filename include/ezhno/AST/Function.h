#ifndef EZHNO_AST_FUNCTION_H
#define EZHNO_AST_FUNCTION_H
#include "ezhno/AST/Decl.h"
namespace ezhno {
class Function : Decl {
  Type& T;
  Name& N;
  Arg* Args;
  unsigned LenOfArgs;
  Body& B;
public:
};
}
#endif /* EZHNO_AST_FUNCTION_H */
