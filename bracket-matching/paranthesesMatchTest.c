#include "testUtils.h"
#include "paranthesesMatch.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_isParanthesesMatching_will_return_true_for_open_and_closed_brace(){
	String input = "Object = {};";
	Stack *stack;
	bool result;
	stack = New(sizeof(char),strlen(input));// stack create
	result = isParanthesesMatching(input, stack);
	ASSERT(true == result);
	free(stack->stack);
	free(stack);
}

void test_isParanthesesMatching_will_return_true_for_open_and_closed_square_brackets(){
	String input = "array[count]=56";
	Stack *stack;
	bool result;
	stack = New(sizeof(char),strlen(input));
	result = isParanthesesMatching(input, stack);
	ASSERT(true == result);
	free(stack->stack);
	free(stack);
}

void test_isParanthesesMatching_will_return_true_for_open_and_closed_circular_brackets(){
	String input = "int doSum = function(num1, num2)";
	Stack *stack;
	bool result;
	stack = New(sizeof(char),strlen(input));
	result = isParanthesesMatching(input, stack);
	ASSERT(true == result);
	free(stack->stack);
	free(stack);
}

void test_isParanthesesMatching_will_return_false_for_only_open_circular_bracket(){
	String input = "int doSum = function(num1, num2";
	Stack *stack;
	bool result;
	stack = New(sizeof(char),strlen(input));
	result = isParanthesesMatching(input, stack);
	ASSERT(false == result);
	free(stack->stack);
	free(stack);
}

void test_isParanthesesMatching_will_return_false_for_only_closed_brace(){
	String input = "void func = function(){\n";
	Stack *stack;
	bool result;
	stack = New(sizeof(char),strlen(input));
	result = isParanthesesMatching(input, stack);
	ASSERT(false == result);
	free(stack->stack);
	free(stack);
}