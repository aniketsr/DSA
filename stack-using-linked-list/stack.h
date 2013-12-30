#include "dList.h"

typedef List Stack;
typedef char String[256];

Stack* createStack();
int push(Stack* stack,void* element);
void* pop(Stack* stack);
void* top(Stack* stack);