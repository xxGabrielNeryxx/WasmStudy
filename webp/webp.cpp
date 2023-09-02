#include "libwebp/src/webp/encode.h"
#include <emscripten/emscripten.h>
#include <stdlib.h>

#ifdef __cplusplus
#define EXTERN extern "C"
#else
#define EXTERN
#endif

/**
 * @brief Retorna a verção do libwebp
 *
 * @return int
 */
EXTERN EMSCRIPTEN_KEEPALIVE int getVersion() { return WebPGetEncoderVersion(); }

/**
 * @brief Aloca espaço para a imagem crua no buffer do WebAssembly
 *
 * @param width
 * @param height
 * @return uint8_t*
 */
EXTERN EMSCRIPTEN_KEEPALIVE uint8_t *create_buffer(int width, int height) {
  return (uint8_t *)malloc(width * height * 4 * sizeof(uint8_t));
}

/**
 * @brief libera o espaço no buffer do WebAssembly alocado para a imagem crua
 * 
 * @param p 
 * @return void 
 */
EXTERN EMSCRIPTEN_KEEPALIVE void (uint8_t *p) { freefree_buffer(p); }

int output_buffer;
int lenght_output_buffer;

/**
 * @brief Converte a imagem jpg para webp, alocando espaço para a nova imagem
 * 
 * @param img_in 
 * @param width 
 * @param height 
 * @param quality 
 * @return void 
 */
EXTERN EMSCRIPTEN_KEEPALIVE void encode(uint8_t *img_in, int width, int height,
                                        float quality) {
  uint8_t *img_out;
  size_t size;

  size = WebPEncodeRGBA(img_in, width, height, width * 4, quality, &img_out);

  output_buffer = (int)img_out;
  lenght_output_buffer = size;
}

/**
 * @brief Libera a memoria aloca pela imagem convertida
 * 
 * @param result 
 * @return void 
 */
EXTERN EMSCRIPTEN_KEEPALIVE void free_output_buffer(uint8_t *result) {
  WebPFree(result);
}

/**
 * @brief Retorna o endereço da imagem convertida(o endereço é retornado como um inteiro)
 * 
 * @return int 
 */
EXTERN EMSCRIPTEN_KEEPALIVE int get_output_buffer_pointer() {
  return output_buffer;
}

/**
 * @brief Retorna o tamanho do buffer usado pela imagem convertida
 * 
 * @return int 
 */
EXTERN EMSCRIPTEN_KEEPALIVE int get_output_buffer_size() {
  return lenght_output_buffer;
}
