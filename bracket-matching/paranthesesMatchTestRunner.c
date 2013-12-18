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

	testStarted("test_isParanthesesMatching_will_return_true_for_open_and_closed_brace");
	setup();
		test_isParanthesesMatching_will_return_true_for_open_and_closed_brace();
	tearDown();
	testEnded();
	testStarted("test_isParanthesesMatching_will_return_true_for_open_and_closed_square_brackets");
	setup();
		test_isParanthesesMatching_will_return_true_for_open_and_closed_square_brackets();
	tearDown();
	testEnded();
	testStarted("test_isParanthesesMatching_will_return_true_for_open_and_closed_circular_brackets");
	setup();
		test_isParanthesesMatching_will_return_true_for_open_and_closed_circular_brackets();
	tearDown();
	testEnded();
	testStarted("test_isParanthesesMatching_will_return_false_for_only_open_circular_bracket");
	setup();
		test_isParanthesesMatching_will_return_false_for_only_open_circular_bracket();
	tearDown();
	testEnded();
	testStarted("test_isParanthesesMatching_will_return_false_for_only_closed_brace");
	setup();
		test_isParanthesesMatching_will_return_false_for_only_closed_brace();
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
