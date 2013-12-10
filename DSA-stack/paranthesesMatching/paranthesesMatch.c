#include "paranthesesMatch.h"
bool isSameParantheses(Stack *stack,char* input){
	if((*input=='}' && *(char*)top(stack)=='{')
	||(*input==')' && *(char*)top(stack)=='(')
	||(*input==']' && *(char*)top(stack)=='[')) return true;
	return false;
}

bool isParanthesesMatching(char * input,Stack *stack){
	int i;
	char * result;
	for (i = 0; i < strlen(input); ++i){
		if(input[i] == '{' || input[i] == '[' || input[i] == '(')
			push(stack,&input[i]);

		if(input[i] == '}' || input[i] == ']' || input[i] == ')'){
			if(isSameParantheses(stack,&input[i])){
				if(top(stack)== NULL) return false;
				if(isSameParantheses(stack, &input[i]))
				pop(stack);
			}
		}
	}
	if(stack->top==-1) return true;
	return false;
}