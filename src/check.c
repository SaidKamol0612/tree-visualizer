#include <stdbool.h>
#include <sys/stat.h>

#include "check.h"

bool is_dir(const char *path)
{
    struct stat st;
    if (stat(path, &st) != 0)
        return false;
    return S_ISDIR(st.st_mode);
}

bool is_executable(const char *path)
{
    struct stat st;
    if (stat(path, &st) != 0)
        return false;
    return (st.st_mode & S_IXUSR);
}