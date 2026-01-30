#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <list.h>

bool addToList(List *list, const char *value)
{
    if (!list || !list->data)
        return false;

    if (list->len >= list->size)
    {
        int new_size = list->size * 2;
        char **new_data = realloc(list->data, new_size * sizeof(char *));
        if (!new_data)
        {
            fprintf(stderr, "Can't re-allocate memory\n");
            return false;
        }
        list->data = new_data;
        list->size = new_size;
    }

    list->data[list->len++] = strdup(value);
    return true;
}

void freeList(List *list)
{
    if (!list)
        return;

    for (size_t i = 0; i < (size_t)list->len; i++)
        free(list->data[i]);

    free(list->data);
    free(list);
}

List *constructList()
{
    List *list = malloc(sizeof *list);
    if (!list)
        return NULL;

    list->size = 10;
    list->len = 0;

    list->data = malloc(list->size * sizeof(char *));
    if (!list->data)
    {
        free(list);
        return NULL;
    }

    list->add = &addToList;
    list->destroy = &freeList;

    return list;
}
