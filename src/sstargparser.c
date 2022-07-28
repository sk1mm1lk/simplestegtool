/*
 * Documentation:
 * https://github.com/sk1mm1lk/simplestegtool/docs/sstargparser.md
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sstargparser.h"
#include <getopt.h>

void help(void)
{
    printf("Usage: simplestegtool -<b|h|d> [OPTION...] -[1|2|3|4|5|6|7] <INPUT FILE> [OUTPUT FILE]\n");
    printf("\n\n");
    printf("Options:\n");
    printf("  Main:\n");
    printf("   -b                 print the least significant bit in binary to the screen\n");
    printf("   -h                 print the least significant bit in hex to the screen\n");
    printf("   -d                 print the least significant bit in hex and binary to the screen\n");
    printf("   -i <start byte>    start least significant bit search from certain byte (inclusive)\n");
    printf("   -f <end byte>      end least significant bit search at certain byte (exclusive)\n");
    printf("   -l <length>        get least significant bit for only a certain number of bytes\n");
    printf("   -o                 get every odd bit in least significant bit search\n");
    printf("   -e                 get every even bit in least significant bit search\n");
    printf("   -p <pattern>       provide a pattern in the form of 1s and 0s for the bits to include\n");
    printf("                          Example: -p 100101\n");
    printf("                          (This will only read the first, fourth and sixth bit per 7 bits\n");
    printf("  Offset:\n");
    printf("   -1                 offset the least significant bit by X (ignore the first X bits)\n");
    printf("   -2\n");
    printf("   -3\n");
    printf("   -4\n");
    printf("   -5\n");
    printf("   -6\n");
    printf("   -7\n");
    return;
}

int is_int(char *input_string)
{
    for (int i = 0; i < strlen(input_string);i++)
    {
        if (input_string[i] < '0' || input_string[i] > '9')
        {
            return 0;
        }
    }
    
    if (strlen(input_string) < 1)
    {
        return 0;
    }
    
    return 1;
}

int is_1_0(char *input_string)
{
    for (int i = 0; i < strlen(input_string);i++)
    {
        if (input_string[i] != '0' || input_string[i] != '1')
        {
            return 0;
        }
    }

    if (strlen(input_string) < 1)
    {
        return 0;
    }

    return 1;
}

void set_arguments(arguments *args)
{
    args->is_binary = 0;
    args->is_hex    = 0;
    args->start     = -1;
    args->finish    = -1;
    args->length    = -1;
    args->is_odd    = 0;
    args->is_even   = 0;
    args->pattern[0]= 0;
    args->offset    = 0;
}

void read_args(int argc, char *argv[], arguments *args, FILE *input_file, FILE *output_file)
{
    set_arguments(args);
        
    int option_char;

    while((option_char = getopt(argc, argv, "bhdi:f:l:oep:1234567")))
    {
        switch (option_char)
        {
            case 'b':
                args->is_binary = 1;
                break;
            case 'h':
                args->is_hex = 1;
                break;
            case 'd':
                args->is_binary = 1;
                args->is_hex = 1;
                break;
            case 'i':
                if(is_int(optarg))
                {
                    args->start = atoi(optarg);
                }
                else
                {
                    printf("Argument i set to non-integer value: \"%s\"\n", optarg);
                    printf("\n\n");
                    help();
                    exit(1);
                }
                break;
            case 'f':
                if(is_int(optarg))
                {
                    args->finish = atoi(optarg);
                }
                else
                {
                    printf("Argument f set to non-integer value: \"%s\"\n", optarg);
                    printf("\n\n");
                    help();
                    exit(1);
                }
                break;
            case 'l':
                if(is_int(optarg))
                {
                    args->length = atoi(optarg);
                }
                else
                {
                    printf("Argument l set to non-integer value: \"%s\"\n", optarg);
                    printf("\n\n");
                    help();
                    exit(1);
                }
                break;
            case 'o':
                args->is_odd = 1;
                break;
            case 'e':
                args->is_even = 1;
                break;
            case 'p':
                if(is_1_0(optarg))
                {
                    if (strlen(optarg) < 100)
                    {
                        for (int i=0; i<strlen(optarg);i++)
                        {
                            args->pattern[i] = optarg[i];
                        }
                        
                        args->pattern[strlen(optarg)] = 0;
                    }
                    else
                    {
                        printf("Argument p allows max of 100 characters: \"%s\" (%d)\n", optarg, strlen(optarg));
                        printf("\n\n");
                        help();
                        exit(0);
                    }
                }
                else
                {
                    printf("Argument p has characters aside from 1 and 0: \"%s\"\n", optarg);
                }
            case '1':
                args->offset = 1;
                break;
            case '2':
                args->offset = 1;
                break;
            case '3':
                args->offset = 1;
                break;
            case '4':
                args->offset = 1;
                break;
            case '5':
                args->offset = 1;
                break;
            case '6':
                args->offset = 1;
                break;
            case '7':
                args->offset = 1;
                break;
            default:
                return;
        }
    }

    /*
     * The file names for input and output
     */
}
