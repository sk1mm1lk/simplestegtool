#include "sstfile-opp.h"

/*
 * Documentation:
 * https://github.com/sk1mm1lk/simplestegtool/docs/sstfile-opp.md
 */

FILE *read_file(char *file_name)
{
    FILE *output_ptr;
    output_ptr = fopen(("%s", file_name), "r");

    return output_ptr;
}
