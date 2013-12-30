#include "testUtils.h"
#include "bSort.h"
#include <stdio.h>
#include <string.h>
typedef char String[256];
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

int compareStrings(void* element1,void* element2){
    return strcmp(*(String*)element1,*(String*)element2);
};

void test_sort_integers_using_bSort(){
  int i,noOfElements = 3,elementsToSort[] = {2,1,3}, expected[] = {1,2,3};
  void *actual[3];
  for(i = 0; i < noOfElements; i++)
    actual[i] = &elementsToSort[i];
  bSort(actual,noOfElements,compareIntegers);
  ASSERT(expected[0] == *(int*)actual[0]);
  ASSERT(expected[1] == *(int*)actual[1]);
  ASSERT(expected[2] == *(int*)actual[2]);
}

void test_sort_chars_using_bSort(){
	int i,noOfElements = 3;
	char elementsToSort[] = {'b','c','a'}, expected[] = {'a','b','c'};
	void *actual[3];
	for(i = 0; i < noOfElements; i++)
		actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareChars);
   	ASSERT(expected[0] == *(char*)actual[0]);
   	ASSERT(expected[1] == *(char*)actual[1]);
   	ASSERT(expected[2] == *(char*)actual[2]);
}

void test_sort_floats_using_bSort(){
	int i,noOfElements = 3;
	float elementsToSort[] = {1.2, 3.2, 2.2}, expected[] = {1.2, 2.2, 3.2};
	void *actual[3];
	for(i = 0; i < noOfElements; i++)
		actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareFloats);
   	ASSERT(expected[0] == *(float*)actual[0]);
   	ASSERT(expected[1] == *(float*)actual[1]);
   	ASSERT(expected[2] == *(float*)actual[2]);
}

void test_sort_doubles_using_bSort(){
	int i,noOfElements = 3;
	double elementsToSort[] = {1.2, 3.2, 2.2}, expected[] = {1.2, 2.2, 3.2};
	void *actual[3];
	for(i = 0; i < noOfElements; i++)
		actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareDoubles);
   	ASSERT(expected[0] == *(double*)actual[0]);
   	ASSERT(expected[1] == *(double*)actual[1]);
   	ASSERT(expected[2] == *(double*)actual[2]);
}

void test_sort_strings_using_bSort(){
  int i,noOfElements = 3;
  String elementsToSort[] = {"survase", "balasaheb", "aniket"}, 
  expected[] = {"aniket", "balasaheb", "survase"};
  void *actual[3];
  for(i = 0; i < noOfElements; i++)
    actual[i] = &elementsToSort[i];
    bSort(actual,noOfElements,compareStrings);
    ASSERT(0 == strcmp(expected[0],*(String*)actual[0]));
    ASSERT(0 == strcmp(expected[1],*(String*)actual[1]));
    ASSERT(0 == strcmp(expected[2],*(String*)actual[2]));
}