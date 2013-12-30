typedef int (*Compare)(void *first,void *second);
void sort(void** base, int numberOfElements, Compare compare);