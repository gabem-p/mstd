#include <string.h>
#include "include/common.h"

typedef struct dict_node dict_node;
struct dict_node {
    dict_node* next;
    string key;
    void* value;
};

typedef struct {
    uint length;
    dict_node* first;
} dict;

dict* dict_new() {
    dict* _dict = malloc(sizeof(dict));
    _dict->length = 0;
    return _dict;
}

void* dict_get(dict* dict, string key) {
    dict_node* node = dict->first;
    int i = 0;
    while (i++ < dict->length) {
        if (strcmp(key, node->key) == 0)
            return node->value;
        node = node->next;
    }

    return null;
}

void dict_remove(dict* dict, string key) {
    dict_node* prev;
    dict_node* node = dict->first;
    int i = 0;
    while (i++ < dict->length) {
        if (strcmp(key, node->key) == 0)
            break;
        prev = node;
        node = node->next;
    }
    if (i == 0)
        dict->first = node->next;
    else
        prev->next = node->next;
    free(node->key);
    free(node);
    dict->length--;
}

void dict_add(dict* dict, string key, void* value) {
    dict_node* node = malloc(sizeof(dict_node));
    node->key = malloc(strlen(key) + 1);
    strcpy(node->key, key);
    node->value = value;
    node->next = dict->first;
    dict->first = node;
    dict->length++;
}

void dict_cleanup(dict* dict) {
    dict_node* node = dict->first;
    int i = 0;
    while (i++ < dict->length) {
        dict_node* next = node->next;
        free(node->key);
        free(node);
        node = next;
    }
    free(dict);
}

typedef struct {
    dict* dict;
    dict_node* current;
    int index;
} dict_iterator;

dict_iterator* dict_iter_new(dict* dict) {
    dict_iterator* iterator = malloc(sizeof(dict_iterator));
    iterator->dict = dict;
    iterator->current = dict->first;
    iterator->index = 0;
    return iterator;
}

void dict_iter_next(dict_iterator* iterator) {
    iterator->current = iterator->current->next;
    iterator->index++;
}

string dict_iter_key(dict_iterator* iterator) { return iterator->current->key; }

void* dict_iter_value(dict_iterator* iterator) { return iterator->current->value; }

void dict_iter_cleanup(dict_iterator* iterator) { free(iterator); }