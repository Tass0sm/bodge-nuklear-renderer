#ifndef _BODGE_NUKLEAR_RENDERER_H
#define _BODGE_NUKLEAR_RENDERER_H

#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING

#ifndef NK_API
#  if defined(_WIN32)
#    define NK_API __declspec(dllexport)
#  elif defined(__GNUC__)
#    define NK_API __attribute__((visibility("default")))
#  else
#    define NK_API extern
#  endif
#endif

#include "nuklear.h"

struct nk_bodge_renderer;

NK_API struct nk_bodge_renderer*
nk_bodge_renderer_create(int max_vertex_buffer, int max_element_buffer);

NK_API void
nk_bodge_render(struct nk_context* ctx, struct nk_bodge_renderer *renderer, int width, int height, float pixel_ratio);

NK_API struct nk_font*
nk_bodge_renderer_font(struct nk_bodge_renderer *renderer);

NK_API void
nk_bodge_renderer_destroy(struct nk_bodge_renderer *renderer);

#endif
