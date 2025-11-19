#include "../common.h"

typedef struct {
    uint capacity;
    uint count;
} stack;

stack* stack_new(uint capacity);
void stack_push(stack* stack, void* item);
void* stack_pop(stack* stack);
void* stack_peek(stack* stack);
void stack_cleanup(stack* stack);