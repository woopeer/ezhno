#ifndef EZHNO_AST_DECL_H
#define EZHNO_AST_DECL_H
namespace ezhno {

class Decl {
  DeclKind Kind;
public:
  enum DeclKind {
    KFunction
  };
  explicit Decl(DeclKind Kind) : Kind(Kind) {}
};

}
#endif /* EZHNO_AST_DECL_H */
