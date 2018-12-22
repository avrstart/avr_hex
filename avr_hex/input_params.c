#include "input_params.h"

uint32_t get_file_lines(FILE *fp)
{
    int ch = 0;
    uint32_t linecount = 0;
    uint32_t charcount = 0;

    while (ch != EOF) {
        ch = getc(fp);
        if (ch == '\n') { ++linecount; }
        if (ch != ' ' && ch != '\n') { ++charcount; }
    }
    printf("Total lines: %d\n", linecount);
    printf("Total chars: %d\n", charcount);

    return linecount;
}

void print_fw_ver(float fw_v)
{
    printf("=======================\n");
    printf("AVR HEX PARSER v.%.1f \n", (double)fw_v);
    printf("=======================\n");
}

void get_input_params(FILE **fp, int arg_n, char *argv[])
{
    if (arg_n != 2 ) {
        //argv[1] = "/media/andy/TOOLS/avr_hex/avr_hex/lesson2.hex";
        printf ("Usage: avr_hex [path to file]\n");
        /*return 0;*/
    }

    *fp = fopen("/media/andy/TOOLS/avr_hex/avr_hex/lesson2.hex", "r");
    if(*fp == NULL) {
        printf("File open error");
    }
}
