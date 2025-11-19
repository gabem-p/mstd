#include "include/common.h"

typedef struct {
    uint capacity;
    uint count;
    void** items;
} stack;

stack* stack_new(uint capacity) {
    stack* _stack = malloc(sizeof(stack));
    _stack->capacity = capacity;
    _stack->count = 0;
    _stack->items = calloc(capacity, sizeof(void*));
    return _stack;
}

void stack_push(stack* stack, void* item) {
    stack->items[stack->count++] = item;
}

void* stack_pop(stack* stack) {
    void* item = stack->items[--stack->count];
    stack->items[stack->count] = null;
    return item;
}

void* stack_peek(stack* stack) {
    return stack->items[stack->count - 1];
}

void stack_cleanup(stack* stack) {
    free(stack->items);
    free(stack);
}