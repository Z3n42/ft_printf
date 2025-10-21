<div align="center">

# 🖨️ ft_printf

### Because ft_putnbr() and ft_putstr() aren't enough

<p>
  <img src="https://img.shields.io/badge/Score-100%2F100-success?style=for-the-badge&logo=42" alt="42 Score"/>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language"/>
  <img src="https://img.shields.io/github/license/Z3n42/ft_printf?style=for-the-badge" alt="License"/>
  <img src="https://img.shields.io/badge/42-Urduliz-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Urduliz"/>
</p>

*A custom implementation of the printf() function, handling variadic arguments and multiple format specifiers.*

[Features](#-features) • [Installation](#%EF%B8%8F-installation) • [Usage](#-usage) • [Format Specifiers](#-format-specifiers) • [Testing](#-testing)

</div>

---

## 📋 Table of Contents

- [About the Project](#-about-the-project)
- [Features](#-features)
- [Installation](#%EF%B8%8F-installation)
- [Usage](#-usage)
- [Format Specifiers](#-format-specifiers)
- [Implementation Details](#-implementation-details)
- [Project Structure](#-project-structure)
- [Testing](#-testing)
- [What I Learned](#-what-i-learned)
- [Norm Compliance](#-norm-compliance)
- [License](#-license)

---

## 🎯 About the Project

**ft_printf** is the second project in the 42 cursus, where we recreate one of C's most versatile functions: `printf()`. This project introduces **variadic functions** and teaches how to handle a variable number of arguments dynamically.

### Why ft_printf?

The `printf()` function is fundamental to C programming, but understanding how it works internally requires deep knowledge of:
- **Variadic functions** using `<stdarg.h>`
- **Format string parsing** and conversion specifiers
- **Type handling** across different data types
- **String formatting** and output management
- **Edge case handling** for various inputs

This implementation becomes a powerful tool that can be added to your libft library for use in future 42 projects.

---

## ✨ Features

<table>
<tr>
<td width="50%">

### 🔤 Character & String Handling
- `%c` - Single character output
- `%s` - String output
- `%%` - Literal percent sign

</td>
<td width="50%">

### 🔢 Numeric Conversions
- `%d` / `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Unsigned hexadecimal (lowercase)
- `%X` - Unsigned hexadecimal (UPPERCASE)

</td>
</tr>
<tr>
<td width="50%">

### 🎯 Pointer Handling
- `%p` - Pointer address in hexadecimal
- Proper NULL pointer handling
- Cross-platform memory address formatting

</td>
<td width="50%">

### ⚡ Optimized Design
- Variadic argument parsing
- Dynamic format string processing
- Return value tracking (characters printed)
- Efficient memory usage

</td>
</tr>
</table>

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

# Clean everything (including libftprintf.a)
make fclean

# Recompile from scratch
make re
```

After running `make`, you'll have a `libftprintf.a` static library ready to use.

---

## 🚀 Usage

### Including in Your Project

1. **Copy ft_printf to your project directory:**
```bash
cp -r ft_printf/ your_project/
```

2. **Include the header in your C files:**
```c
#include "ft_printf.h"
```

3. **Compile your project with ft_printf:**
```bash
gcc -Wall -Wextra -Werror your_file.c -L./ft_printf -lftprintf -o your_program
```

### Example Programs

#### Basic Usage

```c
#include "ft_printf.h"

int main(void)
{
    int     count;

    // Print a simple string
    ft_printf("Hello, World!\n");

    // Print with format specifiers
    count = ft_printf("My name is %s and I'm %d years old\n", "Iñigo", 25);

    // Return value shows number of characters printed
    ft_printf("Characters printed: %d\n", count);

    return (0);
}
```

#### All Format Specifiers

```c
#include "ft_printf.h"

int main(void)
{
    char    c = 'A';
    char    *str = "42 School";
    int     num = -42;
    unsigned int u_num = 42;
    void    *ptr = &num;

    ft_printf("Character: %c\n", c);                    // Character: A
    ft_printf("String: %s\n", str);                     // String: 42 School
    ft_printf("Signed int: %d\n", num);                // Signed int: -42
    ft_printf("Signed int: %i\n", num);                // Signed int: -42
    ft_printf("Unsigned int: %u\n", u_num);            // Unsigned int: 42
    ft_printf("Hex (lowercase): %x\n", u_num);         // Hex (lowercase): 2a
    ft_printf("Hex (UPPERCASE): %X\n", u_num);         // Hex (UPPERCASE): 2A
    ft_printf("Pointer: %p\n", ptr);                   // Pointer: 0x7ffd5e8a9c4c
    ft_printf("Percent sign: %%\n");                   // Percent sign: %

    return (0);
}
```

**Compile and run:**
```bash
gcc example.c -L. -lftprintf -o example
./example
```

---

## 📖 Format Specifiers

### Mandatory Conversions

<details>
<summary><b>All Supported Format Specifiers</b></summary>

| Specifier | Type | Description | Example |
|-----------|------|-------------|---------|
| `%c` | Character | Prints a single character | `ft_printf("%c", 'A')` → `A` |
| `%s` | String | Prints a string of characters | `ft_printf("%s", "Hello")` → `Hello` |
| `%p` | Pointer | Prints pointer address in hex with `0x` prefix | `ft_printf("%p", ptr)` → `0x7ffd5e8a9c4c` |
| `%d` | Signed decimal | Prints a signed decimal integer | `ft_printf("%d", -42)` → `-42` |
| `%i` | Signed decimal | Prints a signed decimal integer (same as %d) | `ft_printf("%i", 42)` → `42` |
| `%u` | Unsigned decimal | Prints an unsigned decimal integer | `ft_printf("%u", 42)` → `42` |
| `%x` | Hexadecimal | Prints unsigned int in lowercase hex | `ft_printf("%x", 255)` → `ff` |
| `%X` | Hexadecimal | Prints unsigned int in UPPERCASE hex | `ft_printf("%X", 255)` → `FF` |
| `%%` | Literal | Prints a percent sign | `ft_printf("%%")` → `%` |

</details>

### Return Value

`ft_printf()` returns the total number of characters printed (excluding the null terminator), just like the original `printf()`.

```c
int count = ft_printf("Hello, %s!\n", "World");
// count will be 14 (including newline)
```

---

## 🔧 Implementation Details

### Core Components

#### Variadic Function Handling

The project uses `<stdarg.h>` macros to handle variable arguments:

```c
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    // Process format string and arguments

    va_end(args);
    return (chars_printed);
}
```

#### Format String Parsing

The function iterates through the format string:
1. Regular characters are printed directly
2. When `%` is encountered, the next character determines the conversion
3. Appropriate conversion function is called with `va_arg()`
4. Return value tracks total characters printed

#### Number to String Conversion

Integers are converted to strings using custom functions:
- **Base 10**: For `%d`, `%i`, `%u`
- **Base 16**: For `%x`, `%X`, `%p`
- **Recursive approach**: Handles digits from most to least significant

### Key Challenges Solved

1. **Handling negative numbers**: Separate logic for signed integers
2. **Pointer formatting**: Adding `0x` prefix and handling NULL pointers
3. **Character counting**: Tracking output length accurately across all conversions
4. **Type safety**: Proper casting and handling of different argument types

---

## 📁 Project Structure

```
ft_printf/
├── 📄 Makefile              # Compilation rules
├── 📄 ft_printf.h           # Header with function prototypes
├── 📄 ft_printf.c           # Main printf implementation
├── 📄 ft_printf_utils.c     # Helper functions for conversions
├── 📄 ft_print_char.c       # Character and string handlers
├── 📄 ft_print_nbr.c        # Number conversion functions
├── 📄 ft_print_hex.c        # Hexadecimal conversion
├── 📄 ft_print_ptr.c        # Pointer handling
└── 📄 README.md             # This file
```

### Makefile Rules

| Rule | Description |
|------|-------------|
| `make` or `make all` | Compiles the library into `libftprintf.a` |
| `make clean` | Removes object files (`.o`) |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Cleans and recompiles everything |

---

## 🧪 Testing

### Recommended Approach

Compare your `ft_printf()` output directly with the original `printf()`:

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_ret, printf_ret;

    // Test strings
    ft_ret = ft_printf("ft_printf: %s\n", "test");
    printf_ret = printf("printf:    %s\n", "test");
    printf("Return values: ft=%d, orig=%d\n\n", ft_ret, printf_ret);

    // Test numbers
    ft_ret = ft_printf("ft_printf: %d %i %u\n", -42, 42, 42);
    printf_ret = printf("printf:    %d %i %u\n", -42, 42, 42);
    printf("Return values: ft=%d, orig=%d\n\n", ft_ret, printf_ret);

    // Test hex
    ft_ret = ft_printf("ft_printf: %x %X\n", 255, 255);
    printf_ret = printf("printf:    %x %X\n", 255, 255);
    printf("Return values: ft=%d, orig=%d\n\n", ft_ret, printf_ret);

    // Test pointers
    int n = 42;
    ft_ret = ft_printf("ft_printf: %p\n", &n);
    printf_ret = printf("printf:    %p\n", (void *)&n);
    printf("Return values: ft=%d, orig=%d\n\n", ft_ret, printf_ret);

    return (0);
}
```

### Community Testers

- **[Francinette](https://github.com/xicodomingues/francinette)** - Comprehensive tester for 42 projects
- **[printfTester](https://github.com/Tripouille/printfTester)** - Specialized printf tester

### Edge Cases to Test

- NULL string: `ft_printf("%s", NULL)`
- NULL pointer: `ft_printf("%p", NULL)`
- Zero values: `ft_printf("%d %u %x", 0, 0, 0)`
- Negative numbers: `ft_printf("%d", INT_MIN)`
- Mixed specifiers: `ft_printf("Mix: %c %s %d %p", 'A', "test", 42, &var)`

---

## 💡 What I Learned

Through this project, I gained deep understanding of:

- ✅ **Variadic Functions**: Using `va_list`, `va_start()`, `va_arg()`, and `va_end()` macros
- ✅ **Format String Parsing**: Iterating and interpreting format specifiers dynamically
- ✅ **Type Conversion**: Converting different data types to string representations
- ✅ **Number Base Conversion**: Implementing decimal and hexadecimal output
- ✅ **Pointer Arithmetic**: Understanding memory addresses and their representation
- ✅ **Return Value Management**: Tracking characters printed across multiple function calls
- ✅ **Library Integration**: Creating a reusable library that mimics standard behavior
- ✅ **Modular Design**: Structuring code for extensibility and maintainability

### Key Challenges

1. **Understanding `va_arg()` Type Promotion**: Integer types smaller than `int` are promoted to `int`
2. **Hexadecimal Conversion**: Implementing efficient base-16 conversion with proper casing
3. **Pointer Formatting**: Handling platform-specific pointer representation and NULL cases
4. **Character Counting Accuracy**: Ensuring return value matches exactly across all paths
5. **Modular Function Design**: Breaking down logic into reusable, testable components

---

## 📏 Norm Compliance

This project strictly follows the **42 Norm** (Norminette v3):
- ✅ Maximum 25 lines per function
- ✅ Maximum 5 functions per file
- ✅ No forbidden functions used (only `write`, `malloc`, `free`, `va_*` macros)
- ✅ Proper variable declarations
- ✅ No memory leaks
- ✅ No segmentation faults or unexpected behavior

---

## 📄 License

This project is part of the 42 School curriculum. Feel free to use and learn from this code, but please don't copy it for your own 42 projects. Understanding comes from doing it yourself! 🚀

---

## 🔗 Related Projects

This library builds upon and complements:

- [libft](https://github.com/Z3n42/42_libft) - Custom C library with essential functions
- [get_next_line](https://github.com/Z3n42/get_next_line) - Reading from file descriptors
- [pipex](https://github.com/Z3n42/pipex) - Unix pipes implementation

And will be used in future projects requiring formatted output.

---

<div align="center">

**Made with ☕ by [Z3n42](https://github.com/Z3n42)**

*42 Urduliz | Circle 1*

[![42 Profile](https://img.shields.io/badge/42_Intra-ingonzal-000000?style=flat&logo=42&logoColor=white)](https://profile.intra.42.fr/users/ingonzal)

</div>
