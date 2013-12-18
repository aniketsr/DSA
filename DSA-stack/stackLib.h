#include <stdbool.h>

typedef struct{
	void *stack;	//stack->stack not readable...e.g stack->elements
	int elementSize;
	int length;
	int top;
}Stack;

Stack *New(int elementSize, int elements);
bool push(Stack *stack, void *element);
void *pop(Stack *stack);
void* top(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);