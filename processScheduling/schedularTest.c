#include "testUtils.h"
#include "schedular.h"
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_process(){
	process *foo = createProcess("abc",40,1);
	ASSERT(strcmp(foo->name,"abc") == 0);
	ASSERT(foo->processTime == 40);
	ASSERT(foo->priority == 1);
}

void test_schedule_process(){
	process *foo = createProcess("abc",40,1);
	scheduler *schedule = scheduleProcess(foo, 1, 10, 200);
	ASSERT(schedule->noOfProcess == 1);
	ASSERT(schedule->timeQuantum == 10);
	ASSERT(schedule->totalTime == 200);
}

void test_executeProcess(){
	process *foo = createProcess("abc",40,1);
	scheduler *schedule = scheduleProcess(foo, 3, 10, 200);
	int res = executeProcess(schedule);
	ASSERT(res = 66);
}