#include <stdbool.h>
typedef struct{
	void* elements;
	int typeSize;
	int rear;
	int length;
}Queue;	

Queue* create(int,int);
bool enqueue(Queue* queue,void* element);
void* dequeue(Queue* queue);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
