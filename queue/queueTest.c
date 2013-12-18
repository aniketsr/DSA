#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
typedef char String[256];

Queue* queue;

void tearDown(){
    free(queue);
}

void test_1_create_queue_for_ineger(){
	int i;
	int zeroes[]={0,0,0};
	queue = create(sizeof(int),3);
	i=memcmp(zeroes,queue->elements,3);
	ASSERT(!i);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}

void test_2_create_queue_for_float_elements(){
	float i;
	float zeroes[]={0.0,0.0,0.0};
	queue = create(sizeof(float),3);
	i=memcmp(zeroes,queue->elements,3);
	ASSERT(!i);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}

void test_3_create_queue_for_double_elements(){
	int i;
	double zeroes[]={0.0,0.0,0.0};
	queue = create(sizeof(double),3);
	i=memcmp(zeroes,queue->elements,3);
	ASSERT(!i);
	ASSERT(queue->typeSize==8);
	ASSERT(queue->rear==-1);
	ASSERT(queue->length==3);
}

void test_4_create_queue_for_String_elements(){
	int i;
	String zeroes[]={0,0,0};
	queue = create(sizeof(String),3);
	i=memcmp(zeroes,queue->elements,3);
	ASSERT(!i);
	ASSERT(256==queue->typeSize);
	ASSERT(-1==queue->rear);
	ASSERT(queue->length==3);
}

void test_5for_insert_int_element_at_front_of_queue(){
	int i;
	int c=5,res;
	queue = create(sizeof(int),5);
	res = enqueue(queue,&c);
	ASSERT(*(int*)queue->elements == 5);
	ASSERT(res==1);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}

void test_6for_insert_float_element_at_front_of_queue(){
	int i;
	int res;
	float c=5.f;
	queue = create(sizeof(float),5);
	res = enqueue(queue,&c);
	ASSERT(*(float*)queue->elements == 5.f);
	ASSERT(res==1);
	ASSERT(queue->typeSize==4);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}

void test_7for_insert_double_element_at_front_of_queue(){
	int i;
	int res;
	double c=5.f;
	queue = create(sizeof(double),5);
	res = enqueue(queue,&c);
	ASSERT(*(double*)queue->elements == 5.f);
	ASSERT(res==1);
	ASSERT(queue->typeSize==8);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}

void test_8for_insert_string_element_at_front_of_queue(){
	int i;
	int res;
	String c="hi";
	queue = create(sizeof(String),5);	
	res = enqueue(queue,&c);
	ASSERT(strcmp(*(String*)queue->elements,"hi")==0);
	ASSERT(res==1);
	ASSERT(queue->typeSize==256);
	ASSERT(queue->rear==0);
	ASSERT(queue->length==5);
}

void test_9for_delete_intger_from_front_of_queue(){
	int d = 6,res;
	queue = create(sizeof(int),2);
	enqueue(queue,&d);
	res = *(int*)dequeue(queue);
	ASSERT(6==res);
	ASSERT(-1==queue->rear);
}

void test_10for_delete_float_element_from_front_of_queue(){
	float c = 5.0,d = 6.0,res;
	queue = create(sizeof(float),2);
	enqueue(queue,&d);
	res = *(float*)dequeue(queue);
	ASSERT(6.0==res);
	ASSERT(-1==queue->rear);
}

void test_11for_delete_String_element_from_front_of_queue(){
	String c = "hi",d = "hello";
	void *res;
	queue = create(sizeof(String),2);
	enqueue(queue,&d);
	res = dequeue(queue);
	ASSERT(strcmp("hello",*(String*)res)==0);
	ASSERT(-1==queue->rear);
}