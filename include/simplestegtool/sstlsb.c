#include "sstlsb.h"

/*
 * Documentation:
 * https://github.com/sk1mm1lk/simplestegtool/docs/sstlsb.md
 */

int lsb_int(char input_byte)
{
    return ((int) input_byte % 2);
}

char lsb_char(char input_byte)
{
    return (input_byte % 2);
}

int lsb_byte_int(char input_array[])
{
    if (((int) sizeof(input_array)) > 8)
    {
        return 0;
    }

    char *input_byte; // Need to fix, bad implementation

    if (((int) sizeof(input_array)) < 8)
    {
        input_byte = runt_byte(input_array);
    }
    else
    {
        for (int i=0; i<8; i++)
        {
            input_byte[i] = input_array[i];
        }
    }

    int output_int = 0;

    for (int i=0; i<8; i++)
    {
        int multiplicator = 1;
        for (int j=0; j<i; j++)
        {
            multiplicator = multiplicator * 2;
        }

        output_int = output_int + (multiplicator * input_byte[i]);
    }

    return output_int;
}    

char lsb_byte_char(char input_array[])
{
    if (((int) sizeof(input_array)) > 8)
    {
        return '\0';
    }

    char *input_byte; // Need to fix, bad implementation

    if (((int) sizeof(input_array)) < 8)
    {
        input_byte = *runt_byte(input_array);
    }
    else
    {
        for (int i=0; i<8; i++)
        {
            input_byte[i] = input_array[i];
        }
    }

    char output_char = '\0';

    for (int i=0; i<8; i++)
    {
        int multiplicator = 1;
        for (int j=0; j<i; j++)
        {
            multiplicator = multiplicator * 2;
        }

        output_char = output_char + (multiplicator * input_byte[i]);
    }

    return output_char;
}

char *runt_byte(char input_array[])
{
    int array_length = (int) sizeof(input_array);
    char output_array[] = {0, 0, 0, 0, 0, 0, 0, 0};

    if (array_length == 8)
    {
        return input_array;
    }
    else if (array_length > 8)
    {
        return output_array;
    }
    else
    {
        for (int i=0; i<8; i++)
        {
            if (i < array_length)
            {
                output_array[i] = 0;
            }
            else
            {
                output_array[i] = input_array[i-(8-array_length)];
            }
        }
    }
    return output_array;
}
