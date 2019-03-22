#ifndef EZHNO_BASIC_TOKENKIND_H
#define EZHNO_BASIC_TOKENKIND_H
namespace ezhno {
namespace token {
enum TokenKind : unsigned short {
#define TOK(X) X,
#include "ezhno/Basic/TokenKinds.def"
  NUM_TOKENS
};
}
} // end of namespace ezhno
#endif

