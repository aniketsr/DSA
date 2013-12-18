#include "testUtils.h"
#include "scheduling.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_process(){
        Process *process = createProcess("p", 25,1);
        ASSERT(process->priority == 1);
        ASSERT(process->time == 25);
        ASSERT(strcmp(process->name,"p") == 0);
        ASSERT(process->next == NULL);
        free(process);
}
void test_create_scheduler(){
        Scheduler *scheduler = createScheduler(10);
        ASSERT(scheduler->head == NULL);
        ASSERT(scheduler->tail == NULL);
        ASSERT(scheduler->total == 0);
        ASSERT(scheduler->timeSlice == 10);
        free(scheduler);
}
void test_insert_process_in_scheduler(){
        Process p = {20,"xyz",1,NULL};
        Scheduler *scheduler = createScheduler(10);
        int result;
        result = insertProcess(scheduler,&p);
        ASSERT(result == 1);
        ASSERT(scheduler->head == &p);
        ASSERT(scheduler->tail == &p);
        ASSERT(scheduler->total == 1);
        free(scheduler);
}

void test_insert_multiple_processes_in_scheduler(){
        Process p = {20,"p",1,NULL};
        Process q = {20,"q",1,NULL};
        Process r = {20,"r",1,NULL};
        Process *temp,*temp2;
        Scheduler *scheduler = createScheduler(10);
        
        insertProcess(scheduler,&p);
        insertProcess(scheduler,&q);
        insertProcess(scheduler,&r);
        
        temp = scheduler->head;
        temp2 = temp->next;

        ASSERT(temp == &p);
     ASSERT(temp2 == &q);
        ASSERT(temp2->next == &r);
        ASSERT(scheduler->head == &p);
        ASSERT(scheduler->tail == &r);
     free(scheduler);
}
void test_execute_process_in_schedule(){
        Process p = {10,"p",1,NULL};
        Scheduler *schedule = createScheduler(10);
        insertProcess(schedule,&p);
        execute(schedule,10);
        ASSERT(p.time == 0);
        free(schedule);
}

void test_execute__two_process_in_scheduler_when_process_is_greater_than_time_quantum(){
        Process p = {20,"p",1,NULL};
        Process two = {10,"two",1,NULL};
        Scheduler *scheduler = createScheduler(10);
        insertProcess(scheduler,&p);
        insertProcess(scheduler,&two);
        execute(scheduler,20);
        ASSERT(p.time == 10);
        ASSERT(two.time == 0);
        free(scheduler);
}