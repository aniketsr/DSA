#include "testUtils.h"
#include "list.h"
#include <stdlib.h>
typedef char String[256];

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_1create_node(){
	int b=5;
	int *a=&b;
	Node expected = {NULL,NULL,NULL};
	Node *actual = createNode(NULL,NULL);
	ASSERT(actual->next == expected.next);
	ASSERT(actual->previous == expected.previous);
	ASSERT(actual->data == expected.data);
}

void test_2create_list_gives_instanceOfList_pointing_to_null(){
	doubleList *list = create();
	ASSERT(list->length == 0);
	ASSERT(list->head->previous == NULL);
}

void test_3insert_element_in_list(){
	int a = 5;
	doubleList *list = create();
	add(list, 0, &a);
	// ASSERT(list->length == 1);
	// ASSERT(*(int*)list->head->data == 5);
}