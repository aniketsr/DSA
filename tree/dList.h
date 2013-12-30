#include "iterator.h"
typedef struct type{
	void *data;
	struct type *next,*previous;
} node;


typedef struct{
	int length;
	node *head,*tail;
} DoubleList;

#ifndef _COMPARE_
#define _COMPARE_
typedef int (*Compare)(void *elementToCompare,void *element);
#endif
DoubleList create();
int insert(DoubleList* dList,int index,void *element);
void dispose(DoubleList dList);
void* getData(DoubleList dList,void *searchElement,Compare cmp);
void sort(DoubleList dList, Compare cmpFunc);
Iterator getIterator(DoubleList *dList);