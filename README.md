<div align="center">

# 🖨️ ft_printf

### Because ft_putnbr() and ft_putstr() aren't enough

<p>
  <img src="https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge&logo=42" alt="42 Score"/>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language"/>
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License"/>
  <img src="https://img.shields.io/badge/42-Urduliz-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Urduliz"/>
</p>

*A custom implementation of the printf() function, handling variadic arguments and multiple format specifiers.*

[Installation](#%EF%B8%8F-installation) • [Usage](#-usage) • [Format Specifiers](#-format-specifiers) • [Implementation](#-implementation-details)

</div>

---

## 📋 Table of Contents

- [About the Project](#-about-the-project)
- [Installation](#%EF%B8%8F-installation)
- [Usage](#-usage)
- [Format Specifiers](#-format-specifiers)
- [Implementation Details](#-implementation-details)
- [Project Structure](#-project-structure)
- [Testing](#-testing)
- [What I Learned](#-what-i-learned)
- [License](#-license)

---

## 🎯 About the Project

**ft_printf** is a project from the 42 cursus where we recreate one of C's most versatile functions: `printf()`. This project introduces **variadic functions** and teaches how to handle a variable number of arguments dynamically.

### Why ft_printf?

Understanding how `printf()` works internally requires knowledge of:
- **Variadic functions** using `<stdarg.h>`
- **Format string parsing** and conversion specifiers
- **Type handling** across different data types
- **Recursive number conversion** for different bases
- **Character counting** for return value tracking

---

## 🛠️ Installation

### Prerequisites

- **GCC** or **Clang** compiler
- **Make**
- Unix-based system (Linux, macOS)

### Clone and Compile

```bash
# Clone the repository
git clone https://github.com/Z3n42/ft_printf.git
cd ft_printf

# Compile the library
make

# Clean object files
make clean

# Clean everything (including printf.a)
make fclean

# Recompile from scratch
make re
```

After running `make`, you'll have a `printf.a` static library ready to use.

---

## 🚀 Usage

### Including in Your Project

1. **Copy ft_printf to your project directory:**
```bash
cp printf.a ft_printf.h your_project/
```

2. **Include the header in your C files:**
```c
#include "ft_printf.h"
```

3. **Compile your project with ft_printf:**
```bash
gcc -Wall -Wextra -Werror your_file.c printf.a -o your_program
```

### Example Program

```c
#include "ft_printf.h"

int main(void)
{
    char    c = 'A';
    char    *str = "Hello";
    int     num = 42;
    void    *ptr = &num;
    int     count;

    // Basic usage
    ft_printf("Character: %c\n", c);
    ft_printf("String: %s\n", str);
    ft_printf("Decimal: %d\n", num);

    // Return value
    count = ft_printf("Hex: %x, Pointer: %p\n", num, ptr);
    ft_printf("Characters printed: %d\n", count);

    return (0);
}
```

**Compile and run:**
```bash
gcc -Wall -Wextra -Werror example.c printf.a -o example
./example
```

---

## 📖 Format Specifiers

### Supported Conversions

<details open>
<summary><b>All Format Specifiers (9 conversions)</b></summary>

| Specifier | Type | Description | Implementation |
|-----------|------|-------------|----------------|
| `%c` | char | Prints a single character | `ft_putchar_fd()` |
| `%s` | string | Prints a string | `ft_putstr_fd()` |
| `%p` | pointer | Prints pointer address with `0x` prefix | `write(1, "0x", 2)` + `ft_putnbr_p()` |
| `%d` | signed int | Prints signed decimal integer | `ft_putnbr_fd()` |
| `%i` | signed int | Prints signed decimal integer (same as %d) | `ft_putnbr_fd()` |
| `%u` | unsigned int | Prints unsigned decimal integer | `ft_putnbr_long()` |
| `%x` | hex lowercase | Prints unsigned int in lowercase hex | `ft_putnbr_hex()` |
| `%X` | hex uppercase | Prints unsigned int in UPPERCASE hex | `ft_putnbr_hexmay()` |
| `%%` | literal | Prints a percent sign | `ft_putchar_fd('%', 1)` |

</details>

### Return Value

`ft_printf()` returns the **total number of characters printed**, matching the behavior of the original `printf()`.

```c
int count = ft_printf("Hello, %s!\n", "World");
// count = 14 (including newline)
```

---

## 🔧 Implementation Details

### Core Architecture

Your implementation uses a **two-function design**:

#### 1. Main Function: `ft_printf()`
```c
int ft_printf(const char *format, ...)
{
    va_list ap;
    int     count = 0;
    int     len = 0;

    va_start(ap, format);

    while (format[count])
    {
        if (format[count] == '%')
        {
            count++;
            len += ft_puts(ap, format, count);  // Handle conversion
            count++;
        }
        else
        {
            ft_putchar_fd(format[count], 1);   // Regular character
            count++;
            len++;
        }
    }

    va_end(ap);
    return (len);
}
```

**Responsibilities:**
- Iterates through format string character by character
- Detects `%` for conversion specifiers
- Delegates conversions to `ft_puts()`
- Tracks and returns character count

#### 2. Conversion Router: `ft_puts()`
```c
int ft_puts(va_list ap, const char *format, int count)
{
    int len = 0;

    if (format[count] == 'c')
        len += ft_putchar_fd(va_arg(ap, int), 1);
    if (format[count] == 's')
        len += ft_putstr_fd(va_arg(ap, char *), 1);
    if (format[count] == 'p')
    {
        len = 2;
        write(1, "0x", 2);
        ft_putnbr_p(va_arg(ap, uintptr_t), 1, &len);
    }
    if (format[count] == 'd' || format[count] == 'i')
        ft_putnbr_fd(va_arg(ap, int), 1, &len);
    if (format[count] == 'u')
        ft_putnbr_long(va_arg(ap, unsigned int), 1, &len);
    if (format[count] == 'x')
        ft_putnbr_hex(va_arg(ap, unsigned int), 1, &len);
    if (format[count] == 'X')
        ft_putnbr_hexmay(va_arg(ap, unsigned int), 1, &len);
    if (format[count] == '%')
        len += ft_putchar_fd('%', 1);

    return (len);
}
```

**Responsibilities:**
- Routes each conversion to appropriate function
- Extracts arguments from `va_list` with `va_arg()`
- Accumulates character count via pointer (`int *len`)
- Returns total characters for this conversion

### Helper Functions

#### Character & String Output
```c
int ft_putchar_fd(char c, int fd);
// Writes single char to fd, returns 1

int ft_putstr_fd(char *s, int fd);
// Writes string to fd, returns length
```

#### Number Conversions (Recursive)
```c
void ft_putnbr_fd(int n, int fd, int *len);
// Signed decimal (handles negative, INT_MIN)

void ft_putnbr_long(long int n, int fd, int *len);
// Unsigned decimal (uses long for safety)

void ft_putnbr_hex(unsigned int n, int fd, int *len);
// Hex lowercase (base 16: 0-9, a-f)

void ft_putnbr_hexmay(unsigned int n, int fd, int *len);
// Hex UPPERCASE (base 16: 0-9, A-F)

void ft_putnbr_p(uintptr_t n, int fd, int *len);
// Pointer address (hex, no 0x prefix - added separately)
```

**All number functions:**
- Use **recursion** to process digits
- Take `int *len` parameter to track character count
- Write directly to file descriptor 1 (stdout)

### Key Design Decisions

#### 1. Length Tracking with Pointers
Instead of returning length, number functions use `int *len` parameter:
```c
int len = 0;
ft_putnbr_fd(42, 1, &len);  // len is updated inside function
return len;
```

**Advantage:** Allows recursive calls to accumulate count naturally.

#### 2. Pointer Format Handling
```c
if (format[count] == 'p')
{
    len = 2;                           // Initialize with "0x" length
    write(1, "0x", 2);                 // Write prefix manually
    ft_putnbr_p(va_arg(ap, uintptr_t), 1, &len);  // Add hex digits
}
```

**Why separate?** Keeps `ft_putnbr_p()` focused on hex conversion only.

#### 3. Independent if Statements
Uses multiple `if` instead of `else if`:
```c
if (format[count] == 'c')
    len += ft_putchar_fd(...);
if (format[count] == 's')
    len += ft_putstr_fd(...);
// No else if - each checked independently
```

**Why?** Simpler logic, easier to maintain (though less efficient).

---

## 📁 Project Structure

```
ft_printf/
├── 📄 LICENSE                # MIT License
├── 📄 Makefile               # Build configuration
├── 📄 ft_printf.h            # Header with all prototypes
├── 📄 ft_printf.c            # Main: ft_printf() + ft_puts()
├── 📄 ft_putchar_fd.c        # Character output
├── 📄 ft_putstr_fd.c         # String output
├── 📄 ft_putnbr_fd.c         # Signed decimal (%d, %i)
├── 📄 ft_putnbr_long.c       # Unsigned decimal (%u)
├── 📄 ft_putnbr_hex.c        # Hex lowercase (%x)
├── 📄 ft_putnbr_hexmay.c     # Hex UPPERCASE (%X)
├── 📄 ft_putnbr_p.c          # Pointer hex (%p)
└── 📂 Main/                  # Testing main
    └── mainprintf.c
```

### File Descriptions

| File | Lines | Purpose |
|------|-------|---------|
| `ft_printf.c` | ~80 | Main loop, format parsing, variadic handling |
| `ft_putchar_fd.c` | ~30 | Output single character |
| `ft_putstr_fd.c` | ~40 | Output string with NULL handling |
| `ft_putnbr_fd.c` | ~45 | Recursive signed int output (base 10) |
| `ft_putnbr_long.c` | ~40 | Recursive unsigned int output (base 10) |
| `ft_putnbr_hex.c` | ~40 | Recursive hex output (lowercase) |
| `ft_putnbr_hexmay.c` | ~40 | Recursive hex output (UPPERCASE) |
| `ft_putnbr_p.c` | ~40 | Recursive pointer address output (hex) |

### Makefile Details

```makefile
NAME = printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = ft_printf \
        ft_putchar_fd \
        ft_putstr_fd \
        ft_putnbr_p \
        ft_putnbr_fd \
        ft_putnbr_long \
        ft_putnbr_hex \
        ft_putnbr_hexmay \

OBJS = $(FILES:=.o)
```

**Total:** 8 source files compiled into `printf.a`

### Make Rules

| Rule | Action |
|------|--------|
| `make` / `make all` | Compiles 8 files → `printf.a` |
| `make clean` | Removes `.o` object files |
| `make fclean` | Removes `.o` and `printf.a` |
| `make re` | Equivalent to `fclean` + `all` |

---

## 🧪 Testing

### Test File Included

Your `Main/mainprintf.c` contains comparison tests:

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    char    a = 'a';
    int     b = 1050;
    char    *c = "deeq";

    // Compare outputs
    ft_printf("mia: c%c, s%s, d%d, x%x, p%p\n", a, c, b, b, 20);
    printf   ("ori: c%c, s%s, d%d, x%x, p%p\n", a, c, b, b, 20);

    return (0);
}
```

**Compile and run:**
```bash
make
gcc Main/mainprintf.c printf.a -o test
./test
```

### Manual Testing Template

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_ret, printf_ret;

    // Test all conversions
    ft_ret     = ft_printf("ft: %c %s %d %i %u %x %X %p %%\n", 
                            'A', "test", -42, 42, 42, 255, 255, &ft_ret);
    printf_ret = printf   ("or: %c %s %d %i %u %x %X %p %%\n", 
                            'A', "test", -42, 42, 42, 255, 255, &printf_ret);

    printf("Return values: ft=%d, orig=%d\n", ft_ret, printf_ret);

    return (0);
}
```

### Edge Cases to Test

```c
// NULL string
ft_printf("%s\n", NULL);              // Should handle gracefully

// NULL pointer
ft_printf("%p\n", NULL);              // Usually prints "0x0"

// Zero values
ft_printf("%d %u %x\n", 0, 0, 0);    // Output: 0 0 0

// Negative numbers
ft_printf("%d\n", -2147483648);       // INT_MIN

// Mixed format
ft_printf("%c%s%d%%\n", 'A', "BC", 3); // Output: ABC3%
```

### Community Testers

- **[printfTester](https://github.com/Tripouille/printfTester)** - Specialized tester
- **[Francinette](https://github.com/xicodomingues/francinette)** - Comprehensive 42 tester

```bash
# Using printfTester
git clone https://github.com/Tripouille/printfTester.git
cd printfTester && make m
```

---

## 💡 What I Learned

Through this project, I gained deep understanding of:

- ✅ **Variadic Functions**: Using `va_list`, `va_start()`, `va_arg()`, `va_end()`
- ✅ **Format String Parsing**: Character-by-character iteration and pattern matching
- ✅ **Recursive Number Conversion**: Converting integers to different bases (10, 16)
- ✅ **Type Casting**: Understanding integer promotion (`char` → `int` in `va_arg`)
- ✅ **Pointer Arithmetic**: Working with `uintptr_t` for memory addresses
- ✅ **Character Counting**: Tracking output length across multiple function calls
- ✅ **Modular Design**: Separating concerns (parsing, conversion, output)
- ✅ **Library Creation**: Archiving with `ar rcs` into static library

### Key Implementation Challenges

1. **Recursive Digit Extraction**: Implementing base-10 and base-16 conversion recursively
2. **Length Tracking Strategy**: Using pointer parameter vs return value
3. **INT_MIN Handling**: Special case for -2147483648 (can't be negated directly)
4. **Pointer Formatting**: Separating "0x" prefix from hex conversion logic
5. **Multiple if Statements**: Understanding tradeoffs vs else-if chain

### Design Insights

**Recursion for Number Conversion:**
```c
void ft_putnbr_fd(int n, int fd, int *len)
{
    if (n == -2147483648)  // INT_MIN special case
    {
        write(fd, "-2147483648", 11);
        *len += 11;
        return;
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        (*len)++;
        n = -n;
    }
    if (n >= 10)
        ft_putnbr_fd(n / 10, fd, len);  // Recursive call

    char c = (n % 10) + '0';
    write(fd, &c, 1);
    (*len)++;
}
```

**Why recursion?**
- Naturally processes digits left-to-right
- Cleaner than iterative with string buffer
- Fits the 25-line limit per function

---

## 📏 Norm Compliance

This project follows the **42 Norm** (Norminette v3):
- ✅ Maximum 25 lines per function
- ✅ Maximum 5 functions per file
- ✅ Allowed functions: `write`, `malloc`, `free`, `va_*` macros
- ✅ No global variables
- ✅ Proper variable declarations
- ✅ No memory leaks

---

## 📄 License

MIT License - See [LICENSE](LICENSE) file for details.

This project is part of the 42 School curriculum. Feel free to use and learn from this code, but please don't copy it for your own 42 projects. Understanding comes from doing it yourself! 🚀

---

## 🔗 Related Projects

This library builds upon:

- **[libft](https://github.com/Z3n42/42_libft)** - Custom C library (though printf is standalone)
- **[get_next_line](https://github.com/Z3n42/get_next_line)** - Line reading from FDs
- **[fdf](https://github.com/Z3n42/fdf)** - 3D wireframe (uses printf for debugging)

---

<div align="center">

**Made with ☕ by [Z3n42](https://github.com/Z3n42)**

*42 Urduliz | Circle 1*

[![42 Profile](https://img.shields.io/badge/42_Intra-ingonzal-000000?style=flat&logo=42&logoColor=white)](https://profile.intra.42.fr/users/ingonzal)

</div>
