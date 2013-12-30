#include "../Linked-List/dList.h"
#include "hashMap.h"

typedef struct {
	void* key;
	void* value;
}hashElement;

hashElement* createObject(void* key,void* value);
void* search(List* bucket,void* key, Compare compare );