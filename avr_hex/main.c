#include "input_params.h"
#include "hex_parser.h"
#include <stdlib.h>

#define VERSION_N 0.1f

int main(int argc, char *argv[])
{
    print_fw_ver(VERSION_N);

    FILE *fp;
    get_input_params(&fp, argc, &argv[1]);

    uint32_t lines = get_file_lines(fp);
    fseek(fp, 0, SEEK_SET);

    char *raw_input_str[64];
    uint8_t raw_bin_str[64];
    char rom_hex_str[64];

    FILE *raw_file;
    raw_file = fopen("raw_file.rom", "w+");
    for(uint32_t i = 0; i < lines; i++) {
        uint16_t counts = 0;
        hex_string_t hexstr;

        fgets((char *)raw_input_str, 64, fp);

        convert_hex_string((uint8_t *)raw_input_str, raw_bin_str, &counts);
        parse_string(raw_bin_str, &hexstr);
        if((hexstr.byte_count % 2) != 0) {
            printf("Something wrong with hexstring len. Job stopped\r\n");
            return 0;
        }

        uint16_t curr_addr = hexstr.address / 2;
        uint16_t end_addr = hexstr.address / 2 + hexstr.byte_count / 2;

        for(uint8_t j = 0; curr_addr < end_addr; j++) {
            sprintf(rom_hex_str, "%.6X:%.4X\n", curr_addr, data_from_addr(&hexstr.data[j*2]));
            fwrite(rom_hex_str , 1 , strlen(rom_hex_str) , raw_file);
            curr_addr++;
        }
    }
    fclose(raw_file);
    fclose(fp);




    return 0;
}
