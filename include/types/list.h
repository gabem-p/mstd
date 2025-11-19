#pragma once

#include "../common.h"

typedef struct {
    uint length;
} list;

// Returns a newly created list
list* list_new();
// Returns the item found at `index` in `list`
void* list_get(list* list, uint index);
// Removes the item found at `index` from `list`
void list_remove(list* list, uint index);
// Adds `data` as a new item to `list`
void list_add(list* list, void* data);
// Sets the value of the item at `index` in `list` to `data`
void list_set(list* list, uint index, void* data);
// Returns the index of the first appearance of `data` in `list`, or -1 if it is not present
int list_index(list* list, void* data);
// Destroy `list` and free its resources
void list_cleanup(list* list);
// Destroy `list` and free it resources, including all items
void list_full_cleanup(list* list);

typedef struct {
} list_iterator;

list_iterator* list_iter_new(list* list);
void list_iter_next(list_iterator* iterator);
void* list_iter_get(list_iterator* iterator);
void list_iter_cleanup(list_iterator* iterator);