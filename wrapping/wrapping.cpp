#include <emscripten/emscripten.h>
#include <iostream>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE int addNums(int a, int b) { return a + b; }

EXTERN EMSCRIPTEN_KEEPALIVE int main() {
  std::cout << "Hello world, " << addNums(3, 4) << "\n";

  return 0;
}