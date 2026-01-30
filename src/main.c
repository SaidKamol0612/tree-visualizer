#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "printer.h"
#include "iter.h"

int main(int argc, char const *argv[])
{
    int use_color = isatty(fileno(stdout));

    const char *dir_path = argc > 1 ? argv[1] : ".";
    const char *root = argc > 3 && strcmp(argv[2], "-r") == 0 ? argv[3] : dir_path;

    print_root(root, use_color);
    iter_dir(dir_path, 0, use_color);

    return 0;
}
