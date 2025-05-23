#ifndef NINECRAFT_GFX_TEXTURES_H
#define NINECRAFT_GFX_TEXTURES_H

#include <stdbool.h>
#include <stdint.h>

#include <ninecraft/android/android_string.h>

enum texture_type {
    texture_type_ub = 0,
    texture_type_us565 = 1,
    texture_type_us5551 = 1,
    texture_type_us4444 = 3
};

enum image_format {
    image_format_u8888,
    image_format_u888,
    image_format_u565,
    image_format_u5551,
    image_format_u4444
};

typedef struct {
    int width;// 0 0x00
    int height; // 4 0x04
    uint8_t *pixels; // 8 0x08
    uint32_t unknown; // 12 0x0c
    uint8_t alpha; // 16 0x10
    uint8_t keep_buffer_data; // 17 0x11
    uint32_t texture_type; // 20 0x14
    uint32_t unknown2; // 24 0x18
} texture_data_t;

typedef struct {
    int width;// 0 0x00
    int height; // 4 0x04
    uint8_t *pixels; // 8 0x08
    uint8_t alpha; // 12 0x0c
    uint8_t keep_buffer_data; // 13 0x0d
} texture_data_old_t;

typedef struct {
    int width;
    int height;
    uint8_t *pixels;
    int format;
    int unknown0;
    int mipmap_level;
} image_data_t;

typedef struct {
    int width;
    int height;
    android_string_gnu_t pixels;
    int format;
    int unknown0;
    int mipmap_level;
} image_data_0_9_0_t;

#endif
