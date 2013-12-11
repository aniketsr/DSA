typedef char String[256];
typedef struct{
	int processTime;
	String name;
	int priority;
	void *next;
}process;

typedef struct 
{
	void *process;
	int noOfProcess;
	int totalTime;
	int timeQuantum;
	void *next;
}scheduler;

process *createProcess(String name,int processTime,int priority);
scheduler *scheduleProcess(process *process,int noOfProcess,int timeQuantum,int totalTime);
int executeProcess(scheduler *schedule);