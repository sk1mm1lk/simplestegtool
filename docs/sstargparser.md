# sstargparser

## Description
- sstargparser is responsible for handling the arguments for simplestegtool

## Structures
- `typedef struct Argparser{} arguments`
    - `int is_binary`
        - Refers to least significant bit being displayed in binary
        - Set to 1 for true and 0 to false
    - `int is_hex`
        - Refers to least significant bit being display in hex
        - Set to 1 for true and 0 to false
    - `int start`
        - Refers to the starting bit (inclusive) for least significant bit
        - Set to -1 if not set by user
    - `int finish`
        - Refers to the ending bit (exclusive) for least significant bit
        - Set to -1 if not set by user
    - `int length`
        - Refers to the number of bits to perform least significant bit on
        - Set to -1 if not set by user
    - `int is_odd`
        - Refers to taking every odd numbered bit for least significant bit
        - Set to 1 for true and 0 to false
    - `int is_even`
        - Refers to taking every even numbered bit for least significant bit
        - Set to 1 for true and 0 to false
    - `char pattern[100]`
        - Set to a char array of '1' and '0'
        - Least significant bit will take every '1' bit and ignore every '0'
        - Least significant bit will loop over the pattern
        - Example
            - "10110"
            - Every 5 bits, the first, third and fourth bit will be read
    - `int offset`
        - Refers to the least significant bit offset
        - Ignore the first `offset` number of bits

## Methods
- `void help(void)`
    - Prints to the screen the usage and options for simplestegtool

- `int is_int(char *input_string)`
    - Takes a character array as an input and checks for numeric characters
    - If a non-numeric character is found, the function returns 0

- `int is_1_0(char *input_string)`
    - Takes a character array as an input and checks for '1' and '0' characters
    - If a character other than '1' and '0' is found, function returns 0

- `void set_arguments(arguments *args)`
    - Takes in arguments pointer
    - Sets the arguments variables to the default values
    - Which are:
        - is_binary  = 0
        - is_hex     = 0
        - start      = -1
        - finish     = -1
        - length     = -1
        - is_odd     = 0
        - is_even    = 0
        - pattern[0] = 0

- `void read_args(int argc, char *argv[], arguments *args, FILE *input_file, FILE *output_file)`
    - Takes in argc and argv
    - Takes in a pointer to an arguments structure
    - Takes in input file pointer
    - Takes in output file pointer
    - Reads all the arguments the user passed to the program
    - Calls `set_arguments`
    - Fills in the variables in the arguments pointer
