#include "testUtils.h"
#include "hashMap.h"
#include <stdlib.h>

int hashCodeGenerator(void* key){
    return *(int*)key % 10;
};

int compareInts(void *a,void *b){
    return *(int*)a - *(int*)b;
};

void test_must_insert_data_into_HashMap(){
    HashMap* map = createHashMap(hashCodeGenerator,compareInts);
    int key =5,value =10;
    void* result;
    put(map,&key,&value);
    result = get(map,&key);
    ASSERT(&value == result);
    dispose(map);
};

void test_must_insert_nultiple_data_into_HashMap(){
    HashMap* map = createHashMap(hashCodeGenerator,compareInts);
    int key[] ={5,10,15},value[]={10,20,30};
    void* result;
    put(map,&key[0],&value[0]);
    put(map,&key[1],&value[1]);
    put(map,&key[2],&value[2]);
    result = get(map, &key[0]);
    ASSERT(&value[0] == result);
    result = get(map, &key[1]);
    ASSERT(&value[1] == result);
    result = get(map, &key[2]);
    ASSERT(&value[2] == result);
    dispose(map);
};

void test_must_not_insert_duplicate_data_into_HashMap(){
    HashMap* map = createHashMap(hashCodeGenerator,compareInts);
    int key[] ={5,5},value[]={10,20};
    void* result;
    put(map,&key[0],&value[0]);
    put(map,&key[1],&value[1]);
    result = get(map, &key[0]);
    ASSERT(&value[0] == result);
    result = get(map, &key[1]);
    ASSERT(&value[1] != result);
};

void test_must_get_data_from_HashMap(){
    HashMap* map = createHashMap(hashCodeGenerator,compareInts);
    int key[] ={5},value[]={10};
    void* result;
    put(map,&key[0],&value[0]);
    result = get(map,&key[0]);
    ASSERT(&value[0] == result);
    dispose(map);
};

void test_must_delete_data_from_HashMap(){
    HashMap* map = createHashMap(hashCodeGenerator,compareInts);
    int key[] ={5,10,15},value[]={10,20,30};
    void* result;
    put(map,&key[0],&value[0]);
    put(map,&key[1],&value[1]);
    put(map,&key[2],&value[2]);
    removeKey(map,&key[1]);
    result = get(map,&key[1]);
    ASSERT(NULL ==result);
    dispose(map);
};