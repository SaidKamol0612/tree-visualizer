#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <linux/limits.h> /* for linux */
// #include <limits.h> /* for cross-platforming */

#include "iter.h"
#include "list.h"
#include "check.h"
#include "printer.h"

bool has_next_stack[MAX_DEPTH];

void iter_dir(const char *dir_path, size_t level, bool use_color)
{
    DIR *dir = opendir(dir_path);
    if (!dir)
    {
        perror("opendir");
        return;
    }

    List *files = constructList();
    List *dirs = constructList();

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);

        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        List *l = is_dir(path) ? dirs : files;
        l->add(l, entry->d_name);
    }

    for (size_t i = 0; i < dirs->len; i++)
    {
        bool last_element = (i == dirs->len - 1) && (files->len == 0);

        print_indention(level, last_element, has_next_stack);
        print_entry(dirs->data[i], true, false, use_color);

        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", dir_path, dirs->data[i]);

        has_next_stack[level] = !last_element;
        iter_dir(path, level + 1, use_color);
    }

    for (size_t i = 0; i < files->len; i++)
    {
        char path[PATH_MAX];
        snprintf(path, sizeof(path), "%s/%s", dir_path, files->data[i]);

        print_indention(level, i == (files->len - 1), has_next_stack);
        print_entry(files->data[i], false, is_executable(path), use_color);
    }

    closedir(dir);

    dirs->destroy(dirs);
    files->destroy(files);
}