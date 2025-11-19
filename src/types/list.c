#include "include/common.h"

typedef struct list_node list_node;
struct list_node {
    list_node* next;
    void* data;
};

typedef struct {
    uint length;
    list_node* first;
    list_node* last;
} list;

list* list_new() {
    list* _list = malloc(sizeof(list));
    _list->length = 0;
    return _list;
}

void* list_get(list* list, uint index) {
    if (index >= list->length)
        return null;
    list_node* node = list->first;
    int i = 0;
    while (i++ < index)
        node = node->next;
    return node->data;
}

void list_remove(list* list, uint index) {
    if (index >= list->length)
        return;
    list_node* prev;
    list_node* node = list->first;
    int i = 0;
    while (i++ < index) {
        prev = node;
        node = node->next;
    }
    if (index == 0)
        list->first = node->next;
    else if (index == list->length - 1)
        list->last = prev;
    else
        prev->next = node->next;
    free(node);
    list->length--;
}

void list_add(list* list, void* data) {
    list_node* node = malloc(sizeof(list_node));
    node->data = data;
    node->next = null;
    if (list->length == 0)
        list->first = node;
    else
        list->last->next = node;
    list->last = node;

    list->length++;
}

void list_set(list* list, uint index, void* data) {
    if (index >= list->length)
        return;
    list_node* node = list->first;
    int i = 0;
    while (i++ < index)
        node = node->next;
    node->data = data;
}

int list_index(list* list, void* data) {
    list_node* node = list->first;
    int i = 0;
    while (i++ < list->length) {
        if (node->data == data)
            return i - 1;
        node = node->next;
    }
    return -1;
}

void list_cleanup(list* list) {
    list_node* node = list->first;
    int i = 0;
    while (i++ < list->length) {
        list_node* next = node->next;
        free(node);
        node = next;
    }
    free(list);
}

void list_full_cleanup(list* list) {
    list_node* node = list->first;
    int i = 0;
    while (i++ < list->length) {
        list_node* next = node->next;
        if (node->data != null)
            free(node->data);
        free(node);
        node = next;
    }
    free(list);
}

typedef struct {
    list* list;
    list_node* current;
    int index;
} list_iterator;

list_iterator* list_iter_new(list* list) {
    list_iterator* iterator = malloc(sizeof(list_iterator));
    iterator->list = list;
    iterator->current = list->first;
    iterator->index = 0;
    return iterator;
}

void list_iter_next(list_iterator* iterator) {
    iterator->current = iterator->current->next;
    iterator->index++;
}

void* list_iter_get(list_iterator* iterator) { return iterator->current->data; }

void list_iter_cleanup(list_iterator* iterator) { free(iterator); }