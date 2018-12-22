#include "hex_convertor.h"

uint8_t Ascii2Hex(uint8_t c)
{
    if (c >= '0' && c <= '9') {
        return (uint8_t)(c - '0');
    }
    if (c >= 'A' && c <= 'F') {
        return (uint8_t)(c - 'A' + 10);
    }
    if (c >= 'a' && c <= 'f') {
        return (uint8_t)(c - 'a' + 10);
    }

    return 0;
}


uint8_t textByte_toUint8(uint8_t *strbuf)
{
    uint8_t hexValue;

    uint8_t first_nibble = Ascii2Hex(*strbuf);
    hexValue = ((first_nibble << 4) & 0xF0);

    strbuf++;

    uint8_t second_nibble = Ascii2Hex(*strbuf);
    hexValue |= second_nibble;

    return hexValue;
}


void convert_hex_string(uint8_t *text_str, uint8_t *bin_str, uint16_t *conv_bytes)
{
    uint8_t *source_str = text_str;

    while(1) {
        switch (*source_str) {
        case '\r':
        case ' ':
        case ':':
            source_str++;
            break;
        case '\n':
            return;
        default:
            bin_str[*conv_bytes] = textByte_toUint8(source_str);
            source_str += 2;
            *conv_bytes += 1;
            break;
        }
    }
}


