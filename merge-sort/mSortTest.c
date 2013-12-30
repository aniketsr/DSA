#include "testUtils.h"
#include "mSort.h"
#include <String.h>

typedef char String[256];
typedef struct{
    int id;
    int age;
} Intern;
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInts(void* element1,void* element2){
    return *(int*)element1 < *(int*)element2;
};

int compareDoubles(void* element1,void* element2){
    return *(double*)element1 < *(double*)element2;
};

int compareChars(void* element1,void* element2){
    return *(char*)element1 < *(char*)element2;
};

int compareStrings(void* element1,void* element2){
    return strcmp(*(String*)element1 , *(String*)element2 )< 0;
};

int compareFloats(void* element1,void* element2){
    return *(float*)element1 < *(float*)element2;
};

int compareIntern(void* element1,void* element2){
    return ((Intern*)element1)->id < ((Intern*)element2)->id;
};

void test_must_sort_integers(){
    int i,length = 3;
    int elementsToSort[] = {3,2,1};
    int expected[] = {1,2,3};
    void* base[3] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2]};
    sort(base,3,compareInts);
    for(i=0;i<length;i++)
        ASSERT(expected[i] == *(int*)base[i]);
};

void test_must_sort_floats(){
    float actual[] = {4,3,1};
    float expected[] = {1,3,4};
    int i;
    void* base[3] = {&actual[0],&actual[1],&actual[2]};
    sort(base, 3, compareFloats);
    for(i=0;i<3;i++)
        ASSERT(expected[i] == *(float*)base[i]);
}

void test_must_sort_doubles(){
    double actual[] = {3.2,5.2,1.2};
    double expected[] = {1.2,3.2,5.2};
    int i;
    void *base[3] = {&actual[0],&actual[1],&actual[2]};
    sort(base,3,compareDoubles);
    for(i=0;i<3;i++)
        ASSERT(expected[i] == *(double*)base[i]);
}

void test_must_sort_characters(){
   char actual[] = {'c','a','b',};
    char expected[] = {'a','b','c'};
    int i;
    void *base[3] = {&actual[0],&actual[1],&actual[2]};
    sort(base,3,compareChars);
    for(i=0;i<3;i++)
        ASSERT(expected[i] == *(char*)base[i]);
}

void test_must_sort_Strings(){
    String actual[] = {"ccc","aaa","bbb"};
    String expected[] = {"aaa","bbb","ccc"};
    int i;
    void *base[3] = {&actual[0],&actual[1],&actual[2]};
    sort(base,3,compareStrings);
    for(i=0;i<3;i++)
        ASSERT(0 == strcmp(expected[i],*(String*)base[i]));
}

void test_must_sort_Interns_by_their_id(){
    int length = 3,i;
    Intern a={4,5};
    Intern b={3,2};
    Intern c={2,3};
    Intern elementsToSort[] = {a,b,c};
    Intern sortedElements[] = {c,b,a};
    void* base[3] = {&elementsToSort[0],&elementsToSort[1],&elementsToSort[2]};
    sort(base,length,compareIntern);
    for(i=0;i<length;i++)
        ASSERT(sortedElements[i].id == ((Intern*)base[i])->id);
};