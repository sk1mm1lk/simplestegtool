#include <stdio.h>
#include "sstfile-opp.h"
#include "sstlsb.h"
#define EOF (-1)

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
	 * Read file and return the pointer [sstfile-opp.h]
	 */
	FILE *file_ptr = read_file(argv[1]);
	
	/*
	 * If file pointer is NULL alert the user and end program
	 */
	if (file_ptr == NULL)
	{
		printf("Invalid file: \"%s\"", argv[1]);
		fclose(file_ptr);
		return 1;
	}
	
	/*
	 * Documentation:
	 * https://github.com/sk1mm1lk/simplestegtool/docs/simplestegtool-cli.md
	 */

	const int WRAP_SIZE = 4;
	int bit_count = 0;
	int byte_count = 0;
	char ch = fgetc(file_ptr);

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
}	
