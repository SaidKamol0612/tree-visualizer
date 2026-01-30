#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "printer.h"

void print_root(const char *name, bool use_color)
{
    if (use_color)
        printf(B_LIGHT_BLUE "%s/\n" COLOER_RESET, name);
    else
        printf("%s/\n", name);
}

void print_indention(size_t level, bool is_last, bool has_hlines[])
{

    for (size_t i = 0; i < level; i++)
    {
        if (has_hlines[i])
            printf("│   ");
        else
            printf("    ");
    }

    printf("%s── ", is_last ? "└" : "├");
}

void print_entry(char *name, bool is_dir, bool is_exe, bool use_color)
{
    if (use_color)
    {
        if (is_dir)
            printf(B_BLUE "%s/\n" COLOER_RESET, name);
        else
        {
            if (is_exe)
                printf(B_GREEN "%s\n" COLOER_RESET, name);
            else
                printf("%s\n", name);
        }
    }
    else
    {
        if (is_dir)
            printf("%s/\n", name);
        else
            printf("%s\n", name);
    }
}