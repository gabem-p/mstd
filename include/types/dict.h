#pragma once

#include "../common.h"

typedef struct {
    uint length;
} dict;

dict* dict_new();
void* dict_get(dict* dict, string key);
void dict_remove(dict* dict, string key);
void dict_add(dict* dict, string key, void* value);
void dict_cleanup(dict* dict);

typedef struct {
} dict_iterator;

dict_iterator* dict_iter_new(dict* dict);
void dict_iter_next(dict_iterator* iterator);
string dict_iter_key(dict_iterator* iterator);
void* dict_iter_value(dict_iterator* iterator);
void dict_iter_cleanup(dict_iterator* iterator);