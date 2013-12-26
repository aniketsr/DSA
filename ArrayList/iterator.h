#include "tree.h"
typedef struct {
	Node* current;
	List* list;
	int index;
} treeIterator;

treeIterator* getIterator(List *list);
Node* next(Iterator* it);
int hasNext(Iterator* it);