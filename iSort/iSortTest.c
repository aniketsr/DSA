#include "testUtils.h"
#include <string.h>
#include "isort.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
        int number;
        char ch;
} Simple;

int compareIntegers(void* element1,void* element2){
        return *(int*)element1 - *(int*)element2;
};

int compareFloats(void* element1,void* element2){
        return *(float*)element1 - *(float*)element2;
};

int compareDoubles(void* element1,void* element2){
        return *(double*)element1 - *(double*)element2;
};

int compareStrings(void* element1,void* element2){
        return strcmp((char*)element1,(char*)element2);
};

int areEqual(void* element1,void* element2,int bytes){
        return 0 == memcmp(element1,element2,bytes);
};

void test_sorting_five_integers(){
        int elementsToSort[] = {3,2,4,5,1};
        int expected[] = {1,2,3,4,5};
        isort(elementsToSort,5,sizeof(int),compareIntegers);
        ASSERT(areEqual(expected,elementsToSort,sizeof(int)*5));
};

void test_sorting_floats(){
        float elementsToSort[] = {10.5f,11.5f,5.5f,6.5f,12.5f};
        float expected[] = {5.5f,6.5f,10.5f,11.5f,12.5f};
        isort(elementsToSort,5,sizeof(float),compareFloats);
        ASSERT(areEqual(expected,elementsToSort,sizeof(float)*5));
};

void test_sorting_doubles(){
        double elementsToSort[] = {100.5,200.5,50.5,60.5,1000.5,2000.5};
        double expected[] = {50.5,60.5,100.5,200.5,1000.5,2000.5};
        isort(elementsToSort,6,sizeof(double),compareDoubles);
        ASSERT(areEqual(expected,elementsToSort,sizeof(double)*6));
};

void test_sorting_strings(){
        String elementsToSort[] = {"aaa","eee","bbb","zzz","yyy"};
        String expected[] = {"aaa","bbb","eee","yyy","zzz"};
        isort(elementsToSort,5,sizeof(String),compareStrings);
        ASSERT(areEqual(expected,elementsToSort,sizeof(String)*5));                
};