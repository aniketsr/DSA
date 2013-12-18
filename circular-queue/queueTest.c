#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>

Queue* queue;
void teardown(){
	dispose(queue);
}
void test_1_create_queue_for_length_of_given_size(){
	int i;
	Queue* queue;
	int zeroes[]={0,0,0};
	queue = create(sizeof(int),3);
	i=memcmp(zeroes,queue->elements,3);
	ASSERT(!i);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->front==-1);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}

void test_2_create_queue_for_float_elements(){
	float i;
	Queue* queue;
	float zeroes[]={0.0,0.0,0.0};
	queue = create(sizeof(float),3);
	i=memcmp(zeroes,queue->elements,3);
	ASSERT(!i);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->front==-1);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}

void test_for_insert_int_element_at_front_of_queue(){
	int i;
	Queue* queue;
	int c=5,res;
	queue = create(sizeof(int),5);
	res = enqueue(queue,&c);
	ASSERT(*(int*)queue->elements == 5);
	ASSERT(res==1);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}
void test_for_insert_char_element_at_front_of_queue(){
	Queue* queue;
	char c='a',res;
	queue = create(sizeof(char),5);
	res = enqueue(queue,&c);
	ASSERT(*(char*)queue->elements == 'a');
	ASSERT(res==1);
	ASSERT(queue->typeSize==1);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}

void test_for_insert_string_element_at_front_of_queue(){
	Queue* queue;
	string a;
	int res;
	strcpy(a,"something");
	queue = create(sizeof(string),5);
	res = enqueue(queue,&a);
	ASSERT(0==strcmp(*(string*)queue->elements,"something"));
	ASSERT(res==1);
	ASSERT(queue->typeSize==256);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}

void test_for_delete_int_element_at_front_of_queue(){
	int i , element;
	Queue* queue;
	int content[]={1,2,3,4,0};
	queue = create(sizeof(int),5);
	queue->elements = content ;
	queue->rear = 4;
	queue->front = -1;
	element = *(int*)dequeue(queue);
	i=memcmp(content,queue->elements,5);
	ASSERT(!i);
	ASSERT(element == 1);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->front==0);
	ASSERT(queue->length==5);
}

void test_for_delete_char_element_at_front_of_queue(){
	int i ;
	char element;
	Queue* queue;
	char content[]={'a','b','c','d','e'};
	queue = create(sizeof(char),5);
	queue->elements = content ;
	queue->rear = 4;
	queue->front = -1;
	element = *(char*)dequeue(queue);
	i=memcmp(content,queue->elements,5);
	ASSERT(!i);
	ASSERT(element == 'a');
	ASSERT(queue->typeSize==1);
	ASSERT(queue->front==0);
	ASSERT(queue->length==5);
}

void test_if_queue_is_full(){
	Queue* queue;
	int c = 5,res;
	queue = create(sizeof(char),2);
	enqueue(queue,&c);
    enqueue(queue,&c);
	enqueue(queue,&c);
	ASSERT(isFull(queue));
}
void test_if_queue_is_empty(){
	Queue* queue;
	int c = 5,res;
	queue = create(sizeof(char),2);
	ASSERT(isEmpty(queue));
}
