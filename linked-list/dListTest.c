#include "testUtils.h"
#include "dList.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

List* dList;

void tearDown(){
        free(dList);
}

void test_to_create_list(){
        dList=create();
        ASSERT(0==dList->length);
}

void test_to_insert_an_element_at_beginning(){
        int data = 2;
        dList = create();
        ASSERT(1==insert(dList, 0, &data));
        ASSERT(1==dList->length);
}

void test_to_insert_element_at_end_of_linked_list(){
        int data=2,data2 =3;
        dList = create();
        ASSERT(1==insert(dList, 0, &data));
        ASSERT(1==insert(dList, 1, &data2));
        ASSERT(2==dList->length);
}

void test_to_insert_element_in_between(){
        int data=2,data2=3;
        dList = create();
        ASSERT(1==insert(dList, 0, &data));
        ASSERT(1==insert(dList, 1, &data2));
        ASSERT(1==insert(dList, 2, &data2));
        ASSERT(1==insert(dList, 1, &data));
        ASSERT(4==dList->length);
}

void test_to_delete_an_element_from_beginning(){
        int data=2,data2=3;
        dList = create();
        ASSERT(1==insert(dList, 0, &data));
        ASSERT(1==insert(dList, 1, &data2));
        ASSERT(1==insert(dList, 2, &data2));
        ASSERT(3==dList->length);
        remove(dList, 0);
        ASSERT(2==dList->length);
}

void test_to_delete_an_element_in_between(){
        int data=2,data2=3;
        dList = create();
        ASSERT(1==insert(dList, 0, &data));
        ASSERT(1==insert(dList, 1, &data2));
        ASSERT(1==insert(dList, 2, &data2));
        ASSERT(3==dList->length);
        remove(dList, 1);
        ASSERT(2==dList->length);
}

void test_to_delete_an_element_from_last(){
        int data=2,data2=3;
        dList = create();
        ASSERT(1==insert(dList, 0, &data));
        ASSERT(1==insert(dList, 1, &data2));
        ASSERT(1==insert(dList, 2, &data2));
        ASSERT(3==dList->length);
        remove(dList, 2        );
        ASSERT(2==dList->length);
}        