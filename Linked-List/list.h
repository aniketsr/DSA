typedef struct{
	void* data;
	void *next,*previous;
}Node;

typedef struct {
	int length;
	Node *head;
}doubleList;

Node* createNode(void *previous, void *next);
doubleList* create();
int add(doubleList *list, int index, void *element);