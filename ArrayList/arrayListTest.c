#include "testUtils.h"
#include "ArrayList.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
        int rollNo;
        char* name;
        int marks;
}sample;

sample first = {1,"abc",10};
sample second = {2,"pqr",20};
sample third = {3,"xyz",30};

const int SUCCESS = 1;
const int FAILURE = 0;
List list;

void setup(){
        int noOfElements = 2;
        list = create(noOfElements);
}

void tearDown(){
        dispose(list.base);
}

void test_must_insert_element_into_array_list(){
        int result = insert(&list, 0, &first);
        sample* actual = (sample*)get(&list, 0);
        ASSERT(SUCCESS == result);
        ASSERT(actual->rollNo == first.rollNo);
}

void test_must_insert_multiple_elements_into_arrayList(){
        sample* actual ;
        insert(&list, 0, &first);
        insert(&list, 1, &second);
        actual = (sample*)get(&list, 0);
        ASSERT(actual->rollNo == first.rollNo);        
        actual = (sample*)get(&list, 1);
        ASSERT(actual->rollNo == second.rollNo);
}

void test_must_insert_an_element_beyond_its_capacity(){
        sample* actual ;
        insert(&list, 0, &first);
        insert(&list, 1, &second);
        insert(&list, 2, &third);
        actual = (sample*)get(&list, 0);
        ASSERT(actual->rollNo == first.rollNo);        
        actual = (sample*)get(&list, 1);
        ASSERT(actual->rollNo == second.rollNo);
}


void test_must_insert_element_in_between_list(){
        sample* actual ;
        add(&list, &first);
        add(&list, &second);
        insert(&list, 1, &third);
        actual = (sample*)get(&list, 0);
        ASSERT(actual->rollNo == first.rollNo);        
        actual = (sample*)get(&list, 1);
        ASSERT(actual->rollNo == third.rollNo);
        actual = (sample*)get(&list, 2);
        ASSERT(actual->rollNo == second.rollNo);
}

void test_must_remove_element_inbetween_a_list(){
        sample* actual ;
        add(&list, &first);
        add(&list, &second);
        add(&list, &third);
        remove(&list, 1);
        actual = (sample*)get(&list, 0);
        ASSERT(actual->rollNo == first.rollNo);        
        actual = (sample*)get(&list, 1);
        ASSERT(actual->rollNo == third.rollNo);
        actual = (sample*)get(&list, 2);
        ASSERT(actual == NULL);
}

void test_6_remove_element_at_beginning(){
        sample* actual ;
        add(&list, &first);
        add(&list, &second);
        add(&list, &third);
        remove(&list, 0);
        actual = (sample*)get(&list, 0);
        ASSERT(actual->rollNo == second.rollNo);        
        actual = (sample*)get(&list, 1);
        ASSERT(actual->rollNo == third.rollNo);
        actual = (sample*)get(&list, 2);
        ASSERT(actual == NULL);
}

void test_must_remove_element_at_end(){
        sample* actual ;
        add(&list, &first);
        add(&list, &second);
        add(&list, &third);
        remove(&list, 2);
        actual = (sample*)get(&list, 0);
        ASSERT(actual->rollNo == first.rollNo);        
        actual = (sample*)get(&list, 1);
        ASSERT(actual->rollNo == second.rollNo);
        actual = (sample*)get(&list, 2);
        ASSERT(actual == NULL);
}

void test_9_insert_element_using_iterations(){
        sample* temp;
        int count =0;
        int expected[]={10,20,30};
        Iterator it = getIterator(&list);
        add(&list, &first);
        add(&list, &second);
        add(&list, &third);
        while(it.hasNext(&it)){
                temp = (sample*)it.next(&it);
                ASSERT(expected[count] == temp->marks);
                count++;
        }
}

void test_must_not_insert_element_at_negative_index(){
        sample* actual ;
        int result = insert(&list, -1, &first);
        ASSERT(result == FAILURE);
}