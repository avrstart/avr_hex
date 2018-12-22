#ifndef INPUT_PARAMS_H
#define INPUT_PARAMS_H

#include <stdio.h>
#include <stdint.h>

uint32_t get_file_lines(FILE *fp);
void print_fw_ver(float fw_v);
void get_input_params(FILE **fp, int arg_n, char *argv[]);

#endif // INPUT_PARAMS_H
