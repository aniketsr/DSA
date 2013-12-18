#include <stdbool.h>

typedef char string[256];
typedef struct{
	void* elements;
	int typeSize;
	int front;
	int rear;
	int length;
}Queue;	

Queue* create(int,int);
bool enqueue(Queue* queue,void* element);
void* dequeue(Queue* queue);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void dispose(Queue* queue);
void* front(Queue* queue);
void* rear(Queue* queue);