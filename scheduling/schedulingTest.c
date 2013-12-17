#include "testUtils.h"
#include "scheduling.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_process(){
        Process *process = createProcess("one", 30,1);
        ASSERT(process->priority == 1);
        ASSERT(process->time == 30);
        ASSERT(strcmp(process->name,"one") == 0);
        ASSERT(process->next == NULL);
        free(process);
}
void test_create_scheduler(){
        Scheduler *scheduler = createScheduler(5);
        ASSERT(scheduler->head == NULL);
        ASSERT(scheduler->tail == NULL);
        ASSERT(scheduler->total == 0);
        ASSERT(scheduler->timeSlice == 5);
        free(scheduler);
}
void test_insert_process_in_scheduler(){
        Process one = {20,"one",1,NULL};
        Scheduler *scheduler = createScheduler(10);
        int result;
        result = insertProcess(scheduler,&one);
        ASSERT(result == 1);
        ASSERT(scheduler->head == &one);
        ASSERT(scheduler->tail == &one);
        ASSERT(scheduler->total == 1);
        free(scheduler);
}

void test_insert_multiple_processes_in_scheduler(){
        Process one = {20,"one",1,NULL};
        Process two = {20,"two",1,NULL};
        Process three = {20,"Three",1,NULL};
        Process *temp,*temp2;
        Scheduler *scheduler = createScheduler(10);
        
        insertProcess(scheduler,&one);
        insertProcess(scheduler,&two);
        insertProcess(scheduler,&three);
        
        temp = scheduler->head;
        temp2 = temp->next;

        ASSERT(temp == &one);
        ASSERT(temp2 == &two);
        ASSERT(temp2->next == &three);
        ASSERT(scheduler->head == &one);
        ASSERT(scheduler->tail == &three);
        free(scheduler);
}
void test_execute_process_in_scheduler(){
        Process one = {10,"one",1,NULL};
        Scheduler *schedule = createScheduler(10);
        insertProcess(schedule,&one);
        execute(schedule,10);
        ASSERT(one.time == 0);
        free(schedule);
}

void test_execute__two_process_in_scheduler_when_process_is_greater_than_time_quantum(){
        Process one = {20,"one",1,NULL};
        Process two = {10,"two",1,NULL};
        Scheduler *scheduler = createScheduler(10);
        insertProcess(scheduler,&one);
        insertProcess(scheduler,&two);
        execute(scheduler,20);
        ASSERT(one.time == 10);
        ASSERT(two.time == 0);
        free(scheduler);
}