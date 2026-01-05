# mini-libc

# libft

*This project has been created as part of the 42 curriculum by [your_login].*

## Description

**libft** is the first project in the 42 curriculum and serves as a foundation for all future projects. The goal is to recreate a personal C library by reimplementing essential functions from the standard C library (libc), along with additional utility functions that will prove useful throughout the curriculum.

This project deepens understanding of basic algorithms, data structures, memory management, and proper C programming practices. By building this library from scratch, you gain intimate knowledge of how fundamental functions work under the hood.

The library is divided into three main parts:
- **Part 1**: Reimplementation of standard libc functions
- **Part 2**: Additional utility functions for string and memory manipulation
- **Part 3**: Linked list manipulation functions

---

## Instructions

### Compilation

To compile the library, simply run:

```bash
make
```

This will generate the `libft.a` static library file.

### Available Make Rules

- `make` or `make all` - Compiles the library
- `make clean` - Removes object files (.o)
- `make fclean` - Removes object files and the library (libft.a)
- `make re` - Rebuilds the entire library from scratch

### Usage in Your Projects

To use libft in your projects:

1. Include the header in your C files:
```c
#include "libft.h"
```

2. Compile your project with the library:
```bash
gcc -Wall -Wextra -Werror your_file.c -L. -lft -o your_program
```

### Compilation Flags

All functions are compiled with the following flags to ensure code quality:
- `-Wall` - Enable all warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors

---

## Library Functions

### Part 1 - Libc Functions

These functions replicate the behavior of standard C library functions, with an `ft_` prefix:

#### Character Classification & Conversion
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is a digit
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable
- `ft_toupper` - Convert character to uppercase
- `ft_tolower` - Convert character to lowercase

#### String Manipulation
- `ft_strlen` - Calculate string length
- `ft_strlcpy` - Size-bounded string copying
- `ft_strlcat` - Size-bounded string concatenation
- `ft_strchr` - Locate first occurrence of character
- `ft_strrchr` - Locate last occurrence of character
- `ft_strncmp` - Compare strings up to n bytes
- `ft_strnstr` - Locate substring in string
- `ft_strdup` - Duplicate string (uses malloc)

#### Memory Manipulation
- `ft_memset` - Fill memory with constant byte
- `ft_bzero` - Zero out memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area (handles overlap)
- `ft_memchr` - Scan memory for character
- `ft_memcmp` - Compare memory areas

#### Conversion
- `ft_atoi` - Convert string to integer
- `ft_calloc` - Allocate and zero-initialize memory

### Part 2 - Additional Functions

Custom utility functions for enhanced string and data manipulation:

- `ft_substr` - Extract substring from string
- `ft_strjoin` - Concatenate two strings (new allocation)
- `ft_strtrim` - Trim characters from beginning and end
- `ft_split` - Split string by delimiter into array
- `ft_itoa` - Convert integer to string
- `ft_strmapi` - Apply function to each character (with index)
- `ft_striteri` - Iterate and modify string in place
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string + newline to file descriptor
- `ft_putnbr_fd` - Output integer to file descriptor

### Part 3 - Linked List Functions

Functions for manipulating singly linked lists using the `t_list` structure:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- `ft_lstnew` - Create new list node
- `ft_lstadd_front` - Add node at beginning
- `ft_lstadd_back` - Add node at end
- `ft_lstsize` - Count list nodes
- `ft_lstlast` - Get last node
- `ft_lstdelone` - Delete single node
- `ft_lstclear` - Delete and free entire list
- `ft_lstiter` - Iterate and apply function to each node
- `ft_lstmap` - Create new list by applying function to each node

---

## Resources

### Documentation
- [C Standard Library Reference](https://en.cppreference.com/w/c)
- [Linux man pages](https://man7.org/linux/man-pages/)
- [GNU C Library Documentation](https://www.gnu.org/software/libc/manual/)

### Articles & Tutorials
- [Understanding C Pointers](https://www.learn-c.org/en/Pointers)
- [Memory Management in C](https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/)
- [Linked Lists in C](https://www.learn-c.org/en/Linked_lists)
- [Makefile Tutorial](https://makefiletutorial.com/)

### AI Usage
AI tools were used for:
- **Documentation**: Generating clear comments and function descriptions
- **Code Review**: Identifying potential bugs and memory leaks
- **Testing Strategy**: Suggesting edge cases and test scenarios
- **Optimization**: Reviewing algorithmic efficiency of implementations

No AI-generated code was directly used in the final implementation. All functions were written manually to ensure deep understanding of the underlying concepts.

---

## Technical Considerations

- No global variables are used
- Helper functions are declared as `static` to limit scope
- All dynamic memory allocations are properly freed
- The library is created using the `ar` command (not libtool)
- Edge cases are handled (NULL pointers, empty strings, boundary conditions)
- Memory leaks are prevented through careful allocation and deallocation

---

## Author

Created by [your_login] as part of the 42 School curriculum.

---

## License

This project is part of the 42 School curriculum and follows its academic guidelines.
