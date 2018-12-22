#ifndef HEX_CONVERTOR_H
#define HEX_CONVERTOR_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t textByte_toUint8(uint8_t *strbuf);
uint8_t Ascii2Hex(uint8_t c);
void convert_hex_string(uint8_t *text_str, uint8_t *bin_str, uint16_t *conv_bytes);

#endif // HEX_CONVERTOR_H
