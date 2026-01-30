#include <stdlib.h>
#include <stdbool.h>

#ifndef ITER_H
#define ITER_H

#define MAX_DEPTH 256

void iter_dir(const char *dir_path, size_t level, bool use_color);

#endif // ITER_H