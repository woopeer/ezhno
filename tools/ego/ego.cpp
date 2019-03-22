#include "llvm/Support/TrailingObjects.h"
#include <iostream>

class A {
  char c;
};

class B {
  double d;
};

class F final : public llvm::TrailingObjects<F, A, B> {
  friend TrailingObjects;
  size_t numTrailingObjects(OverloadToken<A>) const {
    return 0;
  }
  size_t numTrailingObjects(OverloadToken<B>) const {
    return 0;
  }
};

int main () {
  using namespace std;
  F f;
  cout << &f << '\n';
  cout << f.getTrailingObjects<A>() << '\n';
  cout << f.getTrailingObjects<B>() << '\n';
  return 0;
}
