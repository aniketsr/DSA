#include "list.h"
#include <stdlib.h>

Node* createNode(void *previous, void *next){
	Node *element = malloc(sizeof(Node));
	element->previous = previous;
	element->next = next;
	element->data = NULL;
	return element;
}

doubleList* create(){
	doubleList *list = malloc(sizeof(doubleList));
	list->length = 0;
	list->head = createNode(NULL, NULL);
	return list;
}

int add(doubleList *list, int index, void *element){
	Node *previousNode,*nextNode;
	int i;
	if (index > list->length) return 0;
	previousNode = list->head;
	nextNode = previousNode->next;
	for(i=0; i<index; i++){
		nextNode = nextNode->next;
		previousNode = nextNode->previous;
	}
	list->length++;
	previousNode->next = createNode(previousNode,nextNode);
	previousNode->data = element;
	return 1;
}