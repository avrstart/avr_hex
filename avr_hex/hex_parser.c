#include "hex_parser.h"

bool hex_crc(uint8_t *data, uint8_t len)
{
    uint8_t new_crc = 0;
    for(int i = 0; i < len; i++) {
        new_crc += data[i];
    }

    if(new_crc == 0) {
        return true;
    }
    return  false;
}

void parse_string(uint8_t *data_string, hex_string_t *hex_string)
{
    hex_string->byte_count = data_string[0];
    hex_string->address = (uint16_t)(data_string[1] << 8) + (uint16_t)data_string[2];
    hex_string->data_type = data_string[3];
    hex_string->data = &data_string[4];
    hex_string->crc = data_string[hex_string->byte_count + 4];

    if(hex_crc(data_string, 5 + hex_string->byte_count)) {
        printf("crc error\r\n");
        return;
    }
}

uint16_t data_from_addr(uint8_t *data)
{
    uint16_t new_data;
    new_data = (uint16_t)(data[1] << 8) + (uint16_t)data[0];
    return  new_data;
}
