#include "iterator.h"
typedef struct{
	void** base;
	int capacity;
	int length;
}List;

typedef int (*Compare) (void *valueToBeSearch, void* element);
List create(int capacity);
int add(List* list, void* data);
int insert(List* list, int index, void* data);
void* get(List* list, int index);
int remove(List* list, int index);
int search (List* list, Compare areEqual,void* element);
void dispose(void* ptr);
Iterator getIterator(List* list);