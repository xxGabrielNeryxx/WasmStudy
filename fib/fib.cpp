#include <emscripten/emscripten.h>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

EXTERN EMSCRIPTEN_KEEPALIVE int fib(int n) {
  if (n <= 0) {
    return 0;
  }

  int i, t, a = 0, b = 1;

  for (i = 1; i < n; i++) {
    t = a + b;
    a = b;
    b = t;
  }
  return b;
}