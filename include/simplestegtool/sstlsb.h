#ifndef SSTLSB_H
#define SSTLSB_H

/*
 * Documentation:
 * https://github.com/sk1mm1lk/simplestegtool/docs/sstlsb.md
 */

/*
 * Returns the least significant bit as integer
 */
int lsb_int(char input_byte);

/*
 * Return the least significant bit as char
 */
char lsb_char(char input_byte);

/*
 * Returns the decimal value for a byte
 */
int lsb_byte_int(char input_array[]);

/*
 * Returns the ASCII character for a byte
 */
char lsb_byte_char(char input_array[]);

/*
 * Takes in a non 8 element array and returns a zero padded 8 element array
 */
char *runt_byte(char input_array[]);

#endif
