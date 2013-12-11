#include "schedular.h"
#include <stdlib.h>
#include <memory.h>

process *createProcess(String name,int processTime,int priority){
	process *foo = calloc(1,sizeof(process));
	memcpy(foo->name,name,sizeof(String));
	foo->processTime = processTime;
	foo->priority = priority;
	return foo;
}

scheduler *scheduleProcess(process *process,int noOfProcess,int timeQuantum,int totalTime){
	scheduler *schedule = calloc(1, sizeof(scheduler));
	schedule->process = process;
	schedule->noOfProcess = noOfProcess;
	schedule->timeQuantum = timeQuantum;
	schedule->totalTime = totalTime;
	return schedule;
}

int executeProcess(scheduler *schedule){
	int timeSlice = (schedule->totalTime)/(schedule->noOfProcess);
	return timeSlice;
}