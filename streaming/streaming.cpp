#include <emscripten/emscripten.h>

EMSCRIPTEN_KEEPALIVE
int sumOfNInts(int n) { return n * (n + 1) / 2; }