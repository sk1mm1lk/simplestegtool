#include <stdio.h>
#include "sstfile-opp.h"
#include "sstlsb.h"
#define EOF (-1)

/*
 * Documentation:
 * https://github.com/sk1mm1lk/simplestegtool/docs/simplestegtool-cli.md
 */

void lsb_binary(char *file_name);

int main(int argc, char *argv[])
{
    /*
     * Check to see if a file argument was supplied
     */
    if (argc == 1)
    {
        printf("No file was specified");
        return 1;
    }

    /*
     * For each filename in the arguments, print binary lsb
     */
    for (int i = 1; i < argc; i++)
    {
        lsb_binary(argv[i]);
    }
}    

void lsb_binary(char *file_name)
{
    /*
     * Read file and return the pointer [sstfile-opp.h]
     */
    FILE *file_ptr = read_file(file_name);
    
    /*
     * If file pointer is NULL end the function to continue with the next file
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
