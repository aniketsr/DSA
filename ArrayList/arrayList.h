typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);

typedef int Comparator(void* compareWith,void* toCompare);

int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);

int add(ArrayList *list,void* data);

int remove(ArrayList *list, int index);

int search(ArrayList *list, void *data,Comparator* compare);