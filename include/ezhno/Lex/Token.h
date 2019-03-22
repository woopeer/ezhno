#ifndef EZHNO_BASIC_TOKEN_H
#define EZHNO_BASIC_TOKEN_H

#include "ezhno/Basic/TokenKind.h"
#include <string>

namespace ezhno
{

class Token
{
private:
  token::TokenKind Kind;
  unsigned UnitData;
  void* PtrData;

public:
  void setLength(unsigned Len) { UnitData = Len; }
  unsigned getLength() const { return UnitData; }

  void setKind(token::TokenKind K) { Kind = K; }
  unsigned getKind() const { return Kind; }

  template<typename PtrDataTy>
  void setData(PtrDataTy Ptr) { 
    PtrData = reinterpret_cast<void*>(Ptr);
  }
  void* getData() const { return PtrData; }

  std::string toString() const {
    return std::string(static_cast<char*>(getData()), getLength());
  }
};

}
#endif
