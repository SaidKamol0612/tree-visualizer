#include <stdlib.h>
#include <stdbool.h>

#ifndef PRINTER_H
#define PRINTER_H

#define COLOER_RESET "\033[0m"
#define B_GREEN "\033[1;32m"
#define B_BLUE "\033[1;34m"
#define B_LIGHT_BLUE "\033[1;36m"

void print_root(const char *name, bool use_color);
void print_indention(size_t level, bool is_last, bool has_hlines[]);
void print_entry(char *name, bool is_dir, bool is_exe, bool use_color);

#endif // PRINTER_H