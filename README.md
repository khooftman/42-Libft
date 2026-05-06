*This project has been created as part of the 42 curriculum by khooftma.*

# Libft

## Description

Libft is the first project at 42, to complete Milestone 0. The goal is to re-create a collection of standard C library functions, along with additional useful functions that will be implemented in future 42 projects. By building this library from scratch, I gained understanding of memory management, pointer manipulation, and linked list management, among other topics.

## Detailed Library Description
The library is composed of three main categories of functions:

1. **Standard Libc Functions:**
   Re-implementations of essential functions from the standard C library.
   - `ft_isalpha` Checks if a character is alphabetic.
   - `ft_isdigit` Checks if a character is a digit (0-9).
   - `ft_isalnum` Checks if a character is alphanumeric.
   - `ft_isascii` Checks if a character is in the ASCII table.
   - `ft_isprint` Checks if a character is printable (including space).
   - `ft_strlen` Calculates the length of a string.
   - `ft_memset` Fills a memory block with a specific byte.
   - `ft_bzero` Sets a byte string to zero.
   - `ft_memcpy` Copies a memory area to another (no overlap handling).
   - `ft_memmove` Copies memory area safely even if they overlap.
   - `ft_strlcpy` Copies a string to a specific size with NUL-termination (\0).
   - `ft_strlcat` Appends a string to another with size safety.
   - `ft_toupper` Converts a lowercase letter to uppercase.
   - `ft_tolower` Convers an uppercase letter to lowercase.
   - `ft_strchr` Locates the first occurrence of a character in a string.
   - `ft_strrchr` Locates the last occurrence of a character in a string.
   - `ft_strncmp` Compares two strings up to a specified number of characters.
   - `ft_memchr` Locates a byte in a memory block.
   - `ft_memcmp` Compares two memory blocks byte by byte.
   - `ft_strnstr` Locates a substring within a string, limited by length.
   - `ft_atoi` Converts a string to an integer.
   - `ft_calloc` Allocates zero-initialized memory for an array.
   - `ft_strdup` Duplicates a string by allocating new memory.

2. **Additional Functions:**
   Utility functions not found in the standard libc.
   - `ft_substr` Creates a substring from a string.
   - `ft_strjoin` Concatenates two strings into a new allocated string.
   - `ft_strtrim` Removes specified characters from the start and end of a string.
   - `ft_split` Splits a string into an array of strings using a delimiter.
   - `ft_itoa` Converts an integer into a string.
   - `ft_strmapi` Creates a new string by applying a function to each character.
   - `ft_striteri` Applies a function directly to each character of a string by index.
   - `ft_putchar_fd` Outputs a character to a given file descriptor.
   - `ft_putstr_fd` Outputs a string to a given file descriptor.
   - `ft_putendl_fd` Outputs a string followed by a newline to a file descriptor.
   - `ft_putnbr_fd` Outputs an integer to a given file descriptor.

3. **Linked List Functions:**
   Functions to manage and manipulate linked list structures.
   - `ft_lstnew` Creates a new list node.
   - `ft_lstadd_front` Adds a node to the beginning of the list.
   - `ft_lstsize` Counts the number of nodes in the list.
   - `ft_lstlast` Returns the last node of the list.
   - `ft_lstadd_back` Adds a node to the end of the list.
   - `ft_lstdelone` Deletes a node's content and frees the node.
   - `ft_lstclear` Deletes and frees an entire list.
   - `ft_lstiter` Iterates over a list and applies a function to each node's content.
   - `ft_lstmap` Creates a new list by applying a function to each node of an existing list.


## Instructions

Compilation: To compile the library, navigate to the root of the repository and run `make` in the terminal. This will generate the `libft.a` static library file.

```shell
make
```

Usage: The library comes with a header file called `libft.h`which contains prototypes for all the functions in the library. To use the library in your own C project, include the header in your code `#include "libft.h"`. 

```shell
#include "libft.h"
```

To clean the object files and library, run `make clean` and `make fclean` respectively.

```shell
make fclean
```

## Resources

- `man` pages for documentation of original functions.
- `Peer to Peer` learning with fellow students.
- `Francinette` to evaluate and test.

### AI Usage
AI was used in this project for the following tasks:
- **Documentation:** Assisting with the structure of the code.
- **Debugging:** Identifying errors.
- **Conceptual Clarity:** Explaining logic behind pointer manipulation, memory management and linked list functions.

