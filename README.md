*This project has been created as part of the 42 curriculum by khooftma.*

# Libft

## Description

Libft is the first project at 42, to complete Milestone 0. The goal is to re-create a collection of standard C library functions, along with additional useful functions that will be implemented in future 42 projects. By building this library from scratch, I gained a deep understanding of memory management, pointer manipulation, and linked list management, among other topics.

## Detailed Library Description
The library is composed of three main categories of functions:

1. **Standard Libc Functions:**
   Re-implementations of essential functions from the standard C library, such as string manipulation (`ft_strlen`, `ft_strchr`), character checks (`ft_isalpha`, `ft_isdigit`), and memory management (`ft_memset`, `ft_calloc`).

2. **Additional Functions:**
   Utility functions not found in the standard libc, such as `ft_substr` (extracting part of a string), `ft_strjoin` (joining two strings), `ft_split` (splitting strings into an array), and `ft_itoa` (converting integers to strings).
   Functions designed to output data to a specific file descriptor, such as `ft_putchar_fd`, `ft_putstr_fd`, and `ft_putnbr_fd`.

3. **Linked List Functions:**
   Functions to manage and manipulate linked list structures (`t_list`). This includes creating new nodes (`ft_lstnew`), adding nodes to the list (`ft_lstadd_front`, `ft_lstadd_back`), and clearing list memory.

## Instructions

Compilation: To compile the library, navigate to the root of the repository and run `make` in the terminal. This will generate the `libft.a` static library file.

Usage: To use the library in your own C project, include the header in your code `#include "libft.h"`. To clean the object files and library, run `make clean` and `make fclean` respectively.

The library comes with a header file called `libft.h`which contains prototypes for all the functions in the library. 

## Resources

- `man` pages for documentation of original functions

### AI Usage
AI was used in this project for the following tasks:
- **Debugging:** Identifying errors.
- **Documentation:** Assisting with the structure of syntax and translation.
- **Conceptual Clarity:** Explaining logic behind pointer manipulation, memory management and linked list functions.