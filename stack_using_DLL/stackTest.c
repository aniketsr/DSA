#include "testUtils.h"
#include "stack.h"
#include <String.h>

void test_create_stack(){
        Stack* stack = createStack();
        ASSERT(stack->head == NULL);
        ASSERT(stack->length == 0);
}
void test_push_char_element_at_start_of_stack(){
        Stack* stack = createStack();
        char element = 'k';
        push(stack , &element);
        ASSERT(stack->head != NULL);
        ASSERT(*(char*)stack->head->data == 'k');
        ASSERT(stack->length == 1);
}
void test_push_int_element_at_start_of_stack(){
        Stack* stack = createStack();
        int element = 10;
        push(stack , &element);
        ASSERT(stack->head != NULL);
        ASSERT(*(int*)stack->head->data == 10);
        ASSERT(stack->length == 1);
}
void test_push_String_element_at_start_of_stack(){
        Stack* stack = createStack();
        String data = "data";
        push(stack , &data);
        ASSERT(stack->head != NULL);
        ASSERT(0 == strcmp(*(String*)stack->head->data , "data"));
        ASSERT(stack->length == 1);
}
void test_push_float_element_at_start_of_stack(){
        Stack* stack = createStack();
        float element = 10.5f;
        push(stack , &element);
        ASSERT(stack->head != NULL);
        ASSERT(*(float*)stack->head->data == 10.5f);
        ASSERT(stack->length == 1);
}

// TEST cases remaining...