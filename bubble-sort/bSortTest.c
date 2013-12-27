#include "testUtils.h"
#include "bSort.h"
#include <stdio.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers(void* element1,void* element2){
    return *(int*)element1 - *(int*)element2;
};

int compareFloats(void* element1,void* element2){
        return *(float*)element1 - *(float*)element2;
};

int compareDoubles(void* element1,void* element2){
        return *(double*)element1 - *(double*)element2;
};

void test_sort_integers_using_bSort(){
	int elementsToSort[] = {2,3,1}, expected[] = {1,2,3};
	void *e1[3];int i;
	int result;
	for(i = 0;i < 3;i++)
		e1[i] = &elementsToSort[i];
    bSort(e1,3,compareIntegers);
    
    result = memcmp(expected,e1,sizeof(expected));
    ASSERT(result == 0);
}