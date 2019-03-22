#include "ezhno/Lex/Lexer.h"
#include "ezhno/Lex/Token.h"
#include "llvm/ADT/StringRef.h"
#include "clang/Basic/CharInfo.h"
#include <iostream>
using namespace ezhno;

static inline bool
ShouldSkip(const Lexer::buffer_iterator Ptr)
{
  return (*Ptr == ' ') || (*Ptr == '\t') || (*Ptr == '\n');
}

void
Lexer::LexIdentifier(Token& Result, Lexer::buffer_iterator Ptr)
{
  ++ Ptr;
  while (clang::isIdentifierBody(*Ptr))
    ++ Ptr;
  Result.setKind(token::identifier);
  Result.setLength(Ptr - CurBuffer);
  Result.setData(const_cast<char*>(&*CurBuffer));
  if (llvm::StringRef identifier(&*CurBuffer, Result.getLength());
      identifier == "int32")
    Result.setKind(token::kw_int32);
  else if (identifier == "return")
    Result.setKind(token::kw_return);
  CurBuffer = Ptr;
}

void
Lexer::LexNumericConstant(Token& Result, Lexer::buffer_iterator Ptr)
{
  ++ Ptr;
  while (clang::isDigit(*Ptr))
    ++ Ptr;
  FormToken(Result, token::value, Ptr);
}

inline void
Lexer::LexEndOfFile(Token& Result)
{
  Result.setKind(token::eof);
}

void
Lexer::Lex(Token& Result)
{ 
  buffer_iterator Ptr = CurBuffer;
  if (ShouldSkip(Ptr))
    {
      ++ Ptr;
      while (ShouldSkip(Ptr))
        ++ Ptr;
      CurBuffer = Ptr;
    }
  token::TokenKind Kind;
  switch (*Ptr)
    {
    case 0:
      if (Ptr == BufferEnd)
        return LexEndOfFile(Result);
      goto target_token_unknown;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      LexNumericConstant(Result, Ptr);
      return;
    #define PUNCTUATOR(name, spelling) \
    case spelling: \
      Kind = token::pt_ ## name; \
      ++ Ptr; \
      break;
    #include "ezhno/Basic/TokenKinds.def"
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
    case 'G': case 'H': case 'I': case 'J': case 'K': case 'L':
    case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
    case 'S': case 'T': case 'U': case 'V': case 'W': case 'X':
    case 'Y': case 'Z':
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
    case 'g': case 'h': case 'i': case 'j': case 'k': case 'l':
    case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
    case 's': case 't': case 'u': case 'v': case 'w': case 'x':
    case 'y': case 'z':
    case '_':
      LexIdentifier(Result, Ptr);
      return;
target_token_unknown:
    default:
      Kind = token::unknown;
      ++ Ptr;
    }
  FormToken(Result, Kind, Ptr);
}
