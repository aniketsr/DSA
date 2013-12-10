#include "./stackLib.h"
#include <String.h>
#include <stdio.h>
typedef char String[256];

int doPostFix(char *expression,Stack *stack,Stack *stack1){
	int i,count=0;
	int *num1,*num2,*operation,result;

	for (i = 0; i < strlen(expression); ++i){
		if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
			push(stack,&expression[i]);
			count++;}
	}
	for (i = 0; i < strlen(expression)-count; ++i){
			push(stack1,&expression[i]);
	}
	for (i = 0; i < count; ++i)	{
		num1=(int*)pop(stack1);
		num2=(int*)pop(stack1);
		operation=(int*)pop(stack);
		result = num1 operation num2;
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	String expression = "234++";
	Stack *stack = New(sizeof(String),strlen(expression));
	Stack *stack1 = New(sizeof(String),strlen(expression));
	doPostFix(expression,stack,stack1);
	return 0;
}