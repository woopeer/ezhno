#ifndef EZHNO_LEX_LEXER_H
#define EZHNO_LEX_LEXER_H
#include "ezhno/Lex/Token.h"
#include <string>
namespace ezhno {
  class Lexer {
  public:
    using BufferTy = std::string;
    using iterator = BufferTy::iterator;
    using const_iterator = BufferTy::const_iterator;
    using buffer_iterator = const_iterator;
  private:
    BufferTy Buffer;
    buffer_iterator BufferStart;
    buffer_iterator BufferEnd;
    buffer_iterator CurBuffer;
  protected:
    void FormToken(Token& Result, token::TokenKind Kind, buffer_iterator Ptr) {
      unsigned TokenLen = Ptr - CurBuffer;
      Result.setKind(Kind);
      Result.setLength(TokenLen);
      Result.setData(const_cast<char*>(&*CurBuffer));
      CurBuffer = Ptr;
    }
    void LexIdentifier(Token& Result, buffer_iterator Ptr);
    void LexNumericConstant(Token& Result, buffer_iterator Ptr);
    void LexEndOfFile(Token& Result);
  public:
    Lexer (BufferTy& buffer) : 
      Buffer(buffer),
      BufferStart(buffer.begin()), BufferEnd(buffer.end()),
      CurBuffer(BufferStart) {}
    void Lex(Token& Result);
  };
} /* end of namespace ezhno */
#endif
