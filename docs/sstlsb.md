# SimpleStegTool Least Significant Bit Module

## Functions

`int lsb_int(char input_byte)`
- Returns the least significant bit of the char byte in the form of an integer
- Returns 0 or 1 as int
- Example:
```
char char_input = 'A';
printf("%d", lsb_int(char_input));
```

`char lsb_char(char input_byte)`
- Returns the least significant bit of the char byte in the form of a char
- Returns 0 or 1 as char
- Example:
```
char char_input = 'A';
printf("%c", lsb_char(char_input));
```
