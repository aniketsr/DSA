#include "stack.h"
#include <stdlib.h>

Stack* createStack(){
      return create();
};
int push(Stack* stack,void* element){
        return insert(stack , stack->length, element);
};
void* pop(Stack* stack){
        void* data = top(stack);
        remove(stack, stack->length-1);
        return data;
};
void* top(Stack* stack){
        Node* node = stack->head;
        while(node->next != NULL) node = node->next;
        return node->data;
};