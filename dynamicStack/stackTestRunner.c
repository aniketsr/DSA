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

	testStarted("test_creates_a_stack_of_3");
	setup();
		test_creates_a_stack_of_3();
	tearDown();
	testEnded();
	testStarted("test_adds_the_integers_to_stack");
	setup();
		test_adds_the_integers_to_stack();
	tearDown();
	testEnded();
	testStarted("test_adds_the_double_to_yhe_stack");
	setup();
		test_adds_the_double_to_yhe_stack();
	tearDown();
	testEnded();
	testStarted("test_adds_Strings_to_stack");
	setup();
		test_adds_Strings_to_stack();
	tearDown();
	testEnded();
	testStarted("test_doubles_the_length_of_stack_when_stack_is_full");
	setup();
		test_doubles_the_length_of_stack_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_pops_the_top_element_from_the_stack");
	setup();
		test_pops_the_top_element_from_the_stack();
	tearDown();
	testEnded();
	testStarted("test_pops_the_top_element_from_the_stack_Strings");
	setup();
		test_pops_the_top_element_from_the_stack_Strings();
	tearDown();
	testEnded();
	testStarted("test_remove_on_empty_stack");
	setup();
		test_remove_on_empty_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
