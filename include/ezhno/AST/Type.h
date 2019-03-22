#ifndef EZHNO_AST_TYPE_H
#define EZHNO_AST_TYPE_H
namespace ezhno {

class Type {
  TypeKind Kind;
public:
  enum TypeKind {
    KInt32
  };
  explicit Type(TypeKind Kind) : Kind(Kind) {}
};

}
#endif /* EZHNO_AST_TYPE_H */
