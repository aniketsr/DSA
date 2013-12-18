#include "testUtils.h"
#include "stackLib.h"
#include <stdlib.h>
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char String[256];
int areEqual(Stack *expected, Stack *actual){
	int result = expected->length == actual->length && expected->elementSize == actual->elementSize;
	if(!result) return result;
	return 0 == memcmp(expected->stack,actual->stack,actual->elementSize*actual->length);
}

void test_1new_must_create_stack_of_2_Integers(){
	Stack *stack;
	int expectedStack[] = {0,0};
	Stack expected = {expectedStack,4,2,-1};
	stack = New(sizeof(int),2);
	ASSERT(areEqual(stack, &expected));
	free(stack);
}

void test_2new_must_create_stack_of_2_Floats(){
	Stack *stack;
	float expectedStack[] = {0,0};
	Stack expected = {expectedStack,4,2,-1};
	stack = New(sizeof(float),2);
	ASSERT(areEqual(stack, &expected));
	free(stack);
}

void test_3new_must_create_stack_of_2_Doubles(){
	Stack *stack;
	double expectedStack[] = {0,0};
	Stack expected = {expectedStack,8,2,-1};
	stack = New(sizeof(double),2);
	ASSERT(areEqual(stack, &expected));
	free(stack);
}

void test_4new_must_create_stack_of_2_char(){
	Stack *stack;
	char expectedStack[] = {0,0};
	Stack expected = {expectedStack,1,2,-1};
	stack = New(sizeof(char),2);
	ASSERT(areEqual(stack, &expected));
	free(stack);
}

void test_5new_must_create_stack_of_2_Strings(){
	Stack *stack;
	String expectedStack[] = {"\0","\0"};
	Stack expected = {expectedStack,256,2,-1};
	stack = New(sizeof(String),2);
	ASSERT(areEqual(stack, &expected));
	free(stack);
}

void test_6new_must_not_push_element_if_stack_is_full(){
	Stack *stack;
	int expectedStack[] = {0,0};
	Stack expected = {expectedStack,4,2,1};
	stack = New(sizeof(int),2);
	stack->top = 1;
	ASSERT(areEqual(stack, &expected));
	free(stack);
}

void test_7push_an_integer_element_at_top_of_a_stack(){
	bool result;
	Stack* stack;
	int a=10;
	int expectedStack[]={10,0,0,0,0};
	Stack expected={expectedStack,4,5,0};
	void* element=&a;
	stack = New(sizeof(int),5);
	result=push(stack,element);
	ASSERT(true==result);
	ASSERT(areEqual(stack,&expected));
	free(stack);
}

void test_8push_float_element_at_top_of_a_stack(){
	bool result;
	Stack* stack;
	float a=10;
	float expectedStack[]={10,0,0,0,0};
	Stack expected={expectedStack,4,5,0};
	void* element=&a;
	stack = New(sizeof(float),5);
	result=push(stack,element);
	ASSERT(true==result);
	ASSERT(areEqual(stack,&expected));
	free(stack);
}

void test_9push_a_double_element_at_top_of_a_stack(){
	bool result;
	Stack* stack;
	double a=20.5;
	double expectedStack[]={20.5,0,0,0,0};
	Stack expected={expectedStack,8,5,0};
	void* element=&a;
	stack=New(sizeof(double),5);
	result=push(stack,element);
	ASSERT(true==result);
	ASSERT(areEqual(stack,&expected));
	free(stack);
}

void test_10push_an_String_element_at_top_of_a_stack(){
	bool result;
	Stack* stack;
	String a="Hi";
	String expectedStack[]={"Hi","","","",""};
	Stack expected={expectedStack,256,5,0};
	void* element=&a;
	stack = New(sizeof(String),5);
	result=push(stack,element);
	ASSERT(true==result);
	ASSERT(areEqual(stack,&expected));
	free(stack);
}

void test_11pop_a_top_element_from_a_stack(){
	void* result;
	Stack* stack;
	double a=2.5;
	void* element=&a;
	stack=New(sizeof(double),5);
	push(stack,element);
	result=pop(stack);
	ASSERT(-1==stack->top);
	ASSERT(2.5==*(double *)result);
	free(stack);
}

void test_12pop_doesnt_pop_a_element_from_an_empty_stack(){
	void* result;
	Stack* stack;
	double a=20.5;
	void* element=&a;
	stack=New(sizeof(double),5);
	result=pop(stack);
	ASSERT(NULL==result);
	free(stack);
}

void test_12pop_a_top_element_from_a_stack(){
	void* result;
	Stack* stack;
	String a="abc";
	void* element=&a;
	stack=New(sizeof(String),5);
	push(stack,element);
	result=pop(stack);
	ASSERT(-1==stack->top);
	ASSERT(0==strcmp("abc",result));
	free(stack);
}

void test_13top_gives_top_element_from_stack(){
	void* result;
	Stack* stack;
	double a=2.5;
	void* element=&a;
	stack=New(sizeof(double),5);
	push(stack,element);
	result=top(stack);
	ASSERT(0==stack->top);
	ASSERT(2.5==*(double *)result);
	free(stack);
}