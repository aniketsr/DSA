#include "stackLib.h"
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

Stack *New(int elementSize, int elements){
	Stack *stack;
	stack=malloc(sizeof(Stack)*1);
	stack->stack = calloc(elements,elementSize);
	stack->elementSize = elementSize;
	stack->length=elements;
	stack->top = -1;
	return stack;
}

bool push(Stack *stack,void* element){
	int address;
	if(isFull(stack))
		return false;
	stack->top++;
	address=stack->top*stack->elementSize;
	printf("%p\n",stack->stack+address );
	memcpy(stack->stack+address,element,stack->elementSize);
	return true;
}

bool isFull(Stack *stack){
	return stack->top+1 == stack->length; 
}

void* pop(Stack *stack){
	int top=stack->top;
	if(!isEmpty(stack)){
		stack->top--;
		return stack->stack+(top*stack->elementSize);
	}
	return NULL;
}

bool isEmpty(Stack *stack){
	return stack->top == -1; 
}

void* top(Stack *stack){
	if(isEmpty(stack))
		return NULL;	
	return stack->stack+(stack->top*stack->elementSize);
}