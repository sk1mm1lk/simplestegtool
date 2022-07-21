#include "sstfile-opp.h"

FILE *read_file(char *file_name)
{
	FILE *output_ptr;
	output_ptr = fopen(("%s", file_name), "r");

	return output_ptr;
}
