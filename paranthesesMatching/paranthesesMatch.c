#include <string.h> // not necessary
#include "paranthesesMatch.h"
int isSameParantheses(Stack *stack,char* input){
	if((*input=='}' && *(char*)top(stack)=='{')
	||(*input==')' && *(char*)top(stack)=='(')
	||(*input==']' && *(char*)top(stack)=='[')) return 1;
	return 0;
}

int isParanthesesMatching(char * input,Stack *stack){
	int i;
	char * result;
	for (i = 0; i < strlen(input); ++i){
		if(input[i] == '{' || input[i] == '[' || input[i] == '(')
			push(stack,&input[i]);

		if(input[i] == '}' || input[i] == ']' || input[i] == ')'){
			if(isSameParantheses(stack,&input[i])){
				if(top(stack)== NULL) return 0;
				if(isSameParantheses(stack, &input[i]))
				pop(stack);
			}
		}
	}
	if(stack->top==-1) return 1;
	return 0;
}