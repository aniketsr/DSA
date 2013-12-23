#include "dList.h"

typedef struct {
	Node* current;
	List* list;
	int index;
} Iterator;

Iterator* getIterator(List *list);
Node* next(Iterator* it);
int hasNext(Iterator* it);