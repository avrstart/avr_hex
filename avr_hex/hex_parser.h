#ifndef HEX_PARSER_H
#define HEX_PARSER_H

#include <stdbool.h>
#include <stdint.h>
#include "hex_convertor.h"

typedef struct
{
    uint8_t byte_count;
    uint16_t address;
    uint8_t data_type;
    uint8_t *data;
    uint8_t crc;
}hex_string_t;

void parse_string(uint8_t *data_string, hex_string_t *hex_string);
uint16_t data_from_addr(uint8_t *data);

#endif // HEX_PARSER_H
