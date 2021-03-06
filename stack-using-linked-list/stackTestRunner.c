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

	testStarted("test_create_stack");
	setup();
		test_create_stack();
	tearDown();
	testEnded();
	testStarted("test_push_element_at_starting_of_the_stack");
	setup();
		test_push_element_at_starting_of_the_stack();
	tearDown();
	testEnded();
	testStarted("test_push_int_element_at_start_of_stack");
	setup();
		test_push_int_element_at_start_of_stack();
	tearDown();
	testEnded();
	testStarted("test_push_String_element_at_start_of_stack");
	setup();
		test_push_String_element_at_start_of_stack();
	tearDown();
	testEnded();
	testStarted("test_push_float_element_at_start_of_stack");
	setup();
		test_push_float_element_at_start_of_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_integer_element_");
	setup();
		test_pop_integer_element_();
	tearDown();
	testEnded();
	testStarted("test_pop_double_element_");
	setup();
		test_pop_double_element_();
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
