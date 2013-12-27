typedef int (*Compare)(void* element1, void* element2);

void bSort(void** base,int noOfElements, Compare compare);