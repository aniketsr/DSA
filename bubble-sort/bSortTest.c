#include "testUtils.h"
#include "bSort.h"
#include <stdio.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntegers(void* element1,void* element2){
    return *(int*)element1 - *(int*)element2;
};

int compareChars(void* element1,void* element2){
    return *(char*)element1 - *(char*)element2;
};

int compareFloats(void* element1,void* element2){
        return *(float*)element1 - *(float*)element2;
};

int compareDoubles(void* element1,void* element2){
        return *(double*)element1 - *(double*)element2;
};

void test_sort_integers_using_bSort(){
	int i,noOfElements = 3,elementsToSort[] = {2,1,3}, expected[] = {1,2,3};
	void *actual[3];
	for(i = 0; i < noOfElements; i++)
		actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareIntegers);
    for(i = 0; i < noOfElements; i++)
    	ASSERT(expected[i] == *(int*)actual[i]);
}

void test_sort_chars_using_bSort(){
	int i,noOfElements = 3;
	char elementsToSort[] = {'b','c','a'}, expected[] = {'a','b','c'};
	void *actual[3];
	for(i = 0; i < noOfElements; i++)
		actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareChars);
    for(i = 0; i < noOfElements; i++)
    	ASSERT(expected[i] == *(char*)actual[i]);
}

void test_sort_floats_using_bSort(){
	int i,noOfElements = 3;
	float elementsToSort[] = {1.2, 3.2, 2.2}, expected[] = {1.2, 2.2, 3.2};
	void *actual[3];
	for(i = 0; i < noOfElements; i++)
		actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareFloats);
    for(i = 0; i < noOfElements; i++)
    	ASSERT(expected[i] == *(float*)actual[i]);
}

void test_sort_doubles_using_bSort(){
	int i,noOfElements = 3;
	double elementsToSort[] = {1.2, 3.2, 2.2}, expected[] = {1.2, 2.2, 3.2};
	void *actual[3];
	for(i = 0; i < noOfElements; i++)
		actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareDoubles);
    for(i = 0; i < noOfElements; i++)
    	ASSERT(expected[i] == *(double*)actual[i]);
}