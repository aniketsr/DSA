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

	testStarted("test_must_insert_data_into_HashMap");
	setup();
		test_must_insert_data_into_HashMap();
	tearDown();
	testEnded();
	testStarted("test_must_insert_nultiple_data_into_HashMap");
	setup();
		test_must_insert_nultiple_data_into_HashMap();
	tearDown();
	testEnded();
	testStarted("test_must_not_insert_duplicate_data_into_HashMap");
	setup();
		test_must_not_insert_duplicate_data_into_HashMap();
	tearDown();
	testEnded();
	testStarted("test_must_get_data_from_HashMap");
	setup();
		test_must_get_data_from_HashMap();
	tearDown();
	testEnded();
	testStarted("test_must_delete_data_from_HashMap");
	setup();
		test_must_delete_data_from_HashMap();
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
