#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_1new_must_create_stack_of_2_Integers");
	setup();
		test_1new_must_create_stack_of_2_Integers();
	tearDown();
	testEnded();
	testStarted("test_2new_must_create_stack_of_2_Floats");
	setup();
		test_2new_must_create_stack_of_2_Floats();
	tearDown();
	testEnded();
	testStarted("test_3new_must_create_stack_of_2_Doubles");
	setup();
		test_3new_must_create_stack_of_2_Doubles();
	tearDown();
	testEnded();
	testStarted("test_4new_must_create_stack_of_2_char");
	setup();
		test_4new_must_create_stack_of_2_char();
	tearDown();
	testEnded();
	testStarted("test_5new_must_create_stack_of_2_Strings");
	setup();
		test_5new_must_create_stack_of_2_Strings();
	tearDown();
	testEnded();
	testStarted("test_6new_must_not_push_element_if_stack_is_full");
	setup();
		test_6new_must_not_push_element_if_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_7push_an_integer_element_at_top_of_a_stack");
	setup();
		test_7push_an_integer_element_at_top_of_a_stack();
	tearDown();
	testEnded();
	testStarted("test_8push_float_element_at_top_of_a_stack");
	setup();
		test_8push_float_element_at_top_of_a_stack();
	tearDown();
	testEnded();
	testStarted("test_9push_a_double_element_at_top_of_a_stack");
	setup();
		test_9push_a_double_element_at_top_of_a_stack();
	tearDown();
	testEnded();
	testStarted("test_10push_an_String_element_at_top_of_a_stack");
	setup();
		test_10push_an_String_element_at_top_of_a_stack();
	tearDown();
	testEnded();
	testStarted("test_11pop_a_top_element_from_a_stack");
	setup();
		test_11pop_a_top_element_from_a_stack();
	tearDown();
	testEnded();
	testStarted("test_12pop_doesnt_pop_a_element_from_an_empty_stack");
	setup();
		test_12pop_doesnt_pop_a_element_from_an_empty_stack();
	tearDown();
	testEnded();
	testStarted("test_12pop_a_top_element_from_a_stack");
	setup();
		test_12pop_a_top_element_from_a_stack();
	tearDown();
	testEnded();
	testStarted("test_13top_gives_top_element_from_stack");
	setup();
		test_13top_gives_top_element_from_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
