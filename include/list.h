#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct List
{
    size_t size;
    size_t len;
    char **data;

    bool (*add)(struct List *list, const char *value);
    void (*destroy)(struct List *list);
} List;

List *constructList();
bool addToList(List *list, const char *value);
void freeList(List *list);

#endif // LIST_H
