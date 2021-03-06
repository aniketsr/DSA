#include "scheduling.h"
#include <stdlib.h>
#include <string.h>

Process* createProcess(String name,int time,int priority){
        Process *process = calloc(1,sizeof(Process));
        memcpy(process->name,name,sizeof(String));
        process->time = time;
        process->priority = priority;
        process->next = NULL;
        return process;
}
Scheduler* createScheduler(int timeSlice){
        Scheduler *scheduler = calloc(1, sizeof(Scheduler));
        scheduler->head = NULL;
        scheduler->tail = NULL;
        scheduler->total = 0;
        scheduler->timeSlice = timeSlice;
        return scheduler;
}
int insertProcess(Scheduler* scheduler,Process* process){
        Process *first = scheduler->head;
        Process *last;
        int i;
        if(scheduler->head == NULL && scheduler->tail == NULL){
                scheduler->head = process;
                scheduler->tail = process;
                scheduler->total++;
                return 1;
        }
        last = scheduler->tail;
        last->next = process;
        scheduler->tail = process;
        scheduler->total++;
        return 1;
}
void execute(Scheduler* scheduler,int availableTime){
        Process* process = scheduler->head;
        int i,temp=0;
        for(i=1;i<=availableTime;i++){
                if(process->next != NULL && temp == 10){
                        process =process->next;
                        temp = 0;
                }
                if(process->time > 0)
                        process->time--;
                temp = temp+1;
        }
}