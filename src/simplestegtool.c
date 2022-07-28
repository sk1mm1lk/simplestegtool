#include <stdio.h>
#include "sstfile-opp.h"
#include "sstlsb.h"
#include "sstargparser.c"
#define EOF (-1)

/*
 * Documentation:
 * https://github.com/sk1mm1lk/simplestegtool/docs/simplestegtool.md
 */

void lsb_binary(char *file_name);

void start_finish(arguments *args);

int main(int argc, char *argv[])
{
    /*
     * Arguments structure declared in sstargparser.h
     */
    arguments args;
    FILE *input_file;
    FILE *output_file;

    /*
     * Handles all the arguments in sstargparser.h
     */
    read_args(argc, argv, &args, input_file, output_file);

    if (args.is_binary == 0 && args.is_hex == 0)
    {
        printf("Arguments b, h, and d missing\n");
        printf("\n\n");
        help();
        exit(1);
    }

    /*
     * Set start and finish bytes according to arguments
     */
    start_finish(&args);

    /*
     * Check files if they exist
     */
}    

void lsb_binary(char *file_name)
{
    /*
     * Read file and return the pointer [sstfile-opp.h]
     */
    FILE *file_ptr = read_file(file_name);
    
    /*
     * If file pointer is NULL end the function and continue
     */
    if (file_ptr == NULL)
    {
        printf("Invalid file: \"%s\"", file_name);
        fclose(file_ptr);
        return;
    }

    const int WRAP_SIZE = 4;
    int bit_count = 0;
    int byte_count = 0;
    char ch = fgetc(file_ptr);

    printf("\n--------------------\n");
    printf("FILE: %s", file_name);
    printf("\n--------------------\n");

    while (ch != EOF)
    {
        printf("%d", lsb_int(ch));

        switch (bit_count)
        {
            case 3:
                bit_count++;
                printf(" ");
                break;
            case 7:
                bit_count = 0;
                byte_count++;
                printf("   ");
                break;
            default:
                bit_count++;
                break;
        }

        if (byte_count > 0)
        {
            if ((byte_count % WRAP_SIZE == 0) && (bit_count == 0))
            {
                printf("\n");
            }
        }
        ch = fgetc(file_ptr);
    }

    fclose(file_ptr);

    return;
}


void start_finish(arguments *args)
{
    if (args->length != -1)
    {
        if (args->start != -1)
        {
            if (args->finish != -1)
            {
                /*
                 * If all three are set, test if the values add up correctly
                 */
                if ((args->finish - args->start) != args->length)
                {
                    printf("Arguments i, f, and l clash: (%d - %d) != %d\n",
                        args->finish, args->start, args->length);
                    printf("\n\n");
                    help();
                    exit(1);
                }
            }
            else
            {
                /*
                 * Set args->finish to the correct value given length and start
                 */
                args->finish = args->start + args->length;
            }
        }
        else
        {
            if (args->finish != -1)
            {
                /*
                 * args->finish and args->length are set but not args->start
                 */
                args->start = args->finish - args->length;
            }
            else
            {
                /*
                 * Nothing but length has been set
                 */
                args->start = 0;
                args->finish = args->start + args->length;
            }
        }
    }
    else
    {
        if (args->start == -1)
        {
            args->start = 0;
        }
    }
}
