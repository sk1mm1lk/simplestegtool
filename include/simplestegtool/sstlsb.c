/*
 * Documentation:
 * https://github.com/sk1mm1lk/simplestegtool/docs/sstlsb.md
 */

#include "sstlsb.h"

int sstlsb_int(char input_byte)
{
	return ((int) input_byte % 2);
}
