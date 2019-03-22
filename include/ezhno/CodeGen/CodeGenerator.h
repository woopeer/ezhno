#ifndef EZHNO_AST_CODEGENERATOR_H
#define EZHNO_AST_CODEGENERATOR_H
namespace ezhno {

class CodeGenerator {
  public:
    bool HandleTopLevelDecl(Decl& Result);
};

}
#endif /* EZHNO_AST_CODEGENERATOR_H */
