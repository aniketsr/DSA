#include "iterator.h"
#include <stdlib.h>
#include <stdlib.h>


List* create(){
        List* start = calloc(1,sizeof(List));
        start->length=0;
        return start;
}

Node* createNode(void* prevAddress,void* nextAddress){
        Node* newNode = calloc(1, sizeof(Node));
        newNode->next = nextAddress;
        newNode->previous = prevAddress;
        return newNode;
}

void* getElement(List* list,int index){
    int i;
    Node* node = createNode(NULL,NULL);
    Node* temp = createNode(NULL,NULL);
    if(list->head==NULL)    return NULL;
    temp->next = list->head;
    for (i = 0; i <= index; ++i){
        temp = (Node*)temp->next;
        if(i==index)    return temp->data;
    }
    return 0x0;
}

int insert(List *start, int index, void *data){
    Node *head=NULL,*previous=NULL,*next=NULL;
        int i;
        head = start->head;
    while(head!= NULL){
        previous = head;
        head = head->next;
    }
    head = previous;
        if(start->length==0){
                start->head = createNode(previous, next);;
                start->head->data=data;
                start->length++;        
                return 1;
        }
        if(start->length == index){
        head->next = createNode(previous, next);
        head->next->data = data;
        start->length++;
        return 1;
        }
        if(index >= 0 && index < start->length){
                next = previous->next;
                head->next = createNode(previous, next);
                head->data = data;
                start->length ++;
                return 1;
        }
        return 1;        
}

void remove(List *start, int index){
    Node *temp,*temp2;
    int count = 1;
    if(index == 0){
            start->head = start->head->next;
            start->length--;
            return;
    }
    temp = start->head;
    while(count < index){
            temp = temp->next;
            count++;
    }
    temp2=temp->next;
    temp->next = temp->next->next;
    if(temp->next != NULL)
            temp->next->previous = temp;
    free(temp2);
    start->length--;
}

Iterator iterator;

Iterator* getIterator(List *list){
    Iterator *it = (Iterator*)calloc(1, sizeof(Iterator));
    it->list = create();
    it->index = 0;
    it->current = NULL;
    it->list = list;
    return it;
}

int hasNext(Iterator* it){
    return it->index <= it->list->length; 
}

Node* next(Iterator *it){
    int i;
    Node* node;
    node = (Node*)it->list->head;
    for (i = 0; i < it->index; i++)
        node = node->next;
    it->index++;
    return (hasNext(it))?node:NULL; 
}