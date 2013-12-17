typedef char String[256];

typedef struct{
        int time;
        String name;
        int priority;
        void* next;
} Process;

typedef struct{
        void* head;
        void* tail;
        int total;
        int timeSlice;
} Scheduler;

Process* createProcess(String name,int time,int priority);
Scheduler* createScheduler(int timeSlice);
int insertProcess(Scheduler* scheduler,Process* process);
void execute(Scheduler* scheduler,int availableTime);