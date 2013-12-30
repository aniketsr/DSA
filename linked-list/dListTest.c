#include "testUtils.h"
#include "iterator.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

List* dList;

void tearDown(){
        free(dList);
}

void test_must_create_a_list(){
        dList=create();
        ASSERT(0==dList->length);
}

void test_must_insert_an_element_at_beginning_of_list(){
        int num = 5;
        dList = create();
        ASSERT(1==insert(dList, 0, &num));
        ASSERT(1==dList->length);
}

void test_must_insert_element_at_end_of_list(){
        int num1 = 5,num2 = 10;
        dList = create();
        ASSERT(1==insert(dList, 0, &num1));
        ASSERT(1==insert(dList, 1, &num2));
        ASSERT(2==dList->length);
}

void test_must_insert_element_in_between_the_list(){
        int num1 = 5,num2 = 10;
        dList = create();
        ASSERT(1==insert(dList, dList->length, &num1));
        ASSERT(1==insert(dList, dList->length, &num2));
        ASSERT(1==insert(dList, dList->length, &num2));
        ASSERT(1==insert(dList, dList->length, &num1));
        ASSERT(4==dList->length);
}

void test_must_delete_an_element_at_beginning_of_list(){
        int num1 = 5,num2 = 10;
        dList = create();
        ASSERT(1==insert(dList, 0, &num1));
        ASSERT(1==insert(dList, 1, &num2));
        ASSERT(1==insert(dList, 2, &num2));
        ASSERT(3==dList->length);
        remove(dList, 0);
        ASSERT(2==dList->length);
}

void test_must_delete_an_element_in_between_the_list(){
        int num1 = 5,num2 = 10;
        dList = create();
        ASSERT(1==insert(dList, 0, &num1));
        ASSERT(1==insert(dList, 1, &num2));
        ASSERT(1==insert(dList, 2, &num2));
        ASSERT(3==dList->length);
        remove(dList, 1);
        ASSERT(2==dList->length);
}

void test_must_delete_an_element_at_end(){
        int num1 = 5,num2 = 10;
        dList = create();
        ASSERT(1==insert(dList, 0, &num1));
        ASSERT(1==insert(dList, 1, &num2));
        ASSERT(1==insert(dList, 2, &num2));
        ASSERT(3==dList->length);
        remove(dList, 2);
        ASSERT(2==dList->length);
}

void test_iterator_must_iterate_through_list(){
        Iterator* it;
        Node* node;
        List* list = create();
        int i;
        int nums[5] = {1,2,3,4,5};
        for (i = 0; i < 5; ++i){
                insert(list, i, &nums[i]);
                ASSERT(i+1==*(int*)getElement(list, i));
        }
        it = getIterator(list);
        node = next(it);
        ASSERT(1 == *(int*)node->data);
}        