#ifndef SSTARGPARSER_H
#define SSTARGPARSER_H

/*
 * Documentation:
 * https://github.com/sk1mm1lk/simplestegtool/docs/sstargparser.md
 */

#include <stdlib.h>

typedef struct Argparser
{
    int is_binary;
    int is_hex;
    int start;
    int finish;
    int length;
    int is_odd;
    int is_even;
    char pattern[100];
    int  offset;
} arguments;

/*
 * Prints the help screen/instructions
 */
void help(void);

/*
 * Checks if the input string is an integer
 */
int is_int(char *input_string);

/*
 * Checks if the input string contains only 1 and 0
 */
int is_1_0(char *input_string);

/*
 * Sets arguments to the default values
 */
void set_arguments(arguments *args);

/*
 * Reads the commandline arguments and file names for certain arguments
 */
void read_args(int argc, char *argv[], arguments *args, FILE *input_file, FILE *output_file);

#endif
