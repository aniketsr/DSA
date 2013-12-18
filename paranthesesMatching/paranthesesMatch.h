#include <string.h> // not necessary
#include "../DSA-stack/stackLib.h" 
#include <stdio.h> // not necessary
typedef char String[256];

bool isSameParantheses(Stack *stack,char* input);
bool isParanthesesMatching(char * input,Stack *stack);