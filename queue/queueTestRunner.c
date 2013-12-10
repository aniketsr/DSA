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

	testStarted("test_1_create_queue_for_ineger");
	setup();
		test_1_create_queue_for_ineger();
	tearDown();
	testEnded();
	testStarted("test_2_create_queue_for_float_elements");
	setup();
		test_2_create_queue_for_float_elements();
	tearDown();
	testEnded();
	testStarted("test_3_create_queue_for_double_elements");
	setup();
		test_3_create_queue_for_double_elements();
	tearDown();
	testEnded();
	testStarted("test_4_create_queue_for_String_elements");
	setup();
		test_4_create_queue_for_String_elements();
	tearDown();
	testEnded();
	testStarted("test_5for_insert_int_element_at_front_of_queue");
	setup();
		test_5for_insert_int_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_5for_insert_float_element_at_front_of_queue");
	setup();
		test_5for_insert_float_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_5for_insert_double_element_at_front_of_queue");
	setup();
		test_5for_insert_double_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_5for_insert_string_element_at_front_of_queue");
	setup();
		test_5for_insert_string_element_at_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_6for_delete_intger_from_front_of_queue");
	setup();
		test_6for_delete_intger_from_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_7for_delete_float_element_from_front_of_queue");
	setup();
		test_7for_delete_float_element_from_front_of_queue();
	tearDown();
	testEnded();
	testStarted("test_7for_delete_String_element_from_front_of_queue");
	setup();
		test_7for_delete_String_element_from_front_of_queue();
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
