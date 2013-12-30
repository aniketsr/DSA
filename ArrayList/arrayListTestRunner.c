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

	testStarted("test_must_insert_element_into_array_list");
	setup();
		test_must_insert_element_into_array_list();
	tearDown();
	testEnded();
	testStarted("test_must_insert_multiple_elements_into_arrayList");
	setup();
		test_must_insert_multiple_elements_into_arrayList();
	tearDown();
	testEnded();
	testStarted("test_must_insert_an_element_beyond_its_capacity");
	setup();
		test_must_insert_an_element_beyond_its_capacity();
	tearDown();
	testEnded();
	testStarted("test_must_insert_element_in_between_list");
	setup();
		test_must_insert_element_in_between_list();
	tearDown();
	testEnded();
	testStarted("test_must_remove_element_inbetween_a_list");
	setup();
		test_must_remove_element_inbetween_a_list();
	tearDown();
	testEnded();
	testStarted("test_6_remove_element_at_beginning");
	setup();
		test_6_remove_element_at_beginning();
	tearDown();
	testEnded();
	testStarted("test_must_remove_element_at_end");
	setup();
		test_must_remove_element_at_end();
	tearDown();
	testEnded();
	testStarted("test_9_insert_element_using_iterations");
	setup();
		test_9_insert_element_using_iterations();
	tearDown();
	testEnded();
	testStarted("test_must_not_insert_element_at_negative_index");
	setup();
		test_must_not_insert_element_at_negative_index();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
