# ft_printf  
![Language](https://img.shields.io/badge/Language-C-blue)
![42](https://img.shields.io/badge/Made%20at-42%20Heilbronn-blue?style=flat)

An implementation of the `printf` function in C, created as part of the **42 Heilbronn curriculum**.  
This project replicates the behavior of the standard `printf` function while following strict coding norms.



## Features
- Re-implementation of the standard `printf` function.
- Custom string and number formatting logic.
- Modular design, built from scratch with low-level memory and string operations.



## Supported Format Specifiers
`ft_printf` implements the following conversions:
- **%c** – Print a single character
- **%s** – Print a string
- **%p** – Print a pointer address
- **%d / %i** – Print a signed integer
- **%u** – Print an unsigned integer
- **%x / %X** – Print an unsigned integer in hexadecimal (lowercase/uppercase)
- **%%** – Print a literal percent sign

## Supported Flags
The following **flags** are implemented to modify the output format:

- **`'-'`** – Left-align the result within the given field width (default is right alignment).  
  Example: `%-5d` will print `42   ` (with spaces to the right).

- **`'0'`** – Pad the number with zeros instead of spaces (only works for numeric conversions).  
  Example: `%05d` will print `00042`.

- **`'#'`** – Alternate form: for `%x` or `%X`, prefix with `0x` or `0X`.  
  Example: `%#x` will print `0x2a`.

- **`' '` (space)** – Insert a leading space before positive numbers (ignored if `+` is present).  
  Example: `% d` will print ` 42`.

- **`'+'`** – Always show the sign for numeric values (`+` for positive, `-` for negative).  
  Example: `%+d` will print `+42`.


## Development Constraints
This project was developed under the **42 school norms**, which impose strict coding rules:
- **Maximum 25 lines per function**.
- **Maximum 5 functions per file**.
- **Maximum 4 parameters per function**.
- **No `for` loops** (only `while` loops allowed).
- **No `do-while` loops**.
- **No `switch-case` statements**.
- Other style and structural constraints as defined by the 42 coding standard.



## Project Structure
- **include/** – Header files (`ft_printf.h`).
- **src/** – Source files containing the implementation of `ft_printf` and utilities.
- **Makefile** – Build instructions.



## Build & Usage

### Build the Library
```bash
make
```
This will compile the source code and create `libftprintf.a`, the static library.

### Use in your Project  
Include the header:
```bash
#include "ft_printf.h"
```
Compile with:  
```bash
gcc your_file.c libftprintf.a -o your_program
```

## Example
```bash
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! The number is %d.\n", "world", 42);
    return 0;
}
```

## Credits
Created at 42 Heilbronn as part of the core curriculum.  
Developed under the rigorous coding standards of the 42 school.
