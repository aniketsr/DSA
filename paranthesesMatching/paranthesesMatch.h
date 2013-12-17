#include <string.h>
#include "../stackLib.h"
#include <stdio.h>
typedef char String[256];

bool isSameParantheses(Stack *stack,char* input);
bool isParanthesesMatching(char * input,Stack *stack);