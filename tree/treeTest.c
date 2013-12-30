#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

const int SUCCESS = 1;

int compareInts(void *a,void *b){
	return *(int*)a - *(int*)b;
}

void test_must_insert_root_node(){
	Tree tree = createTree(compareInts);
	int data = 2;
	int result = insertIntoTree(&tree, NULL, &data);
	ASSERT(SUCCESS == result);
	disposeTree(&tree);
}

void test_must_insert_node_at_second_level(){
	Tree tree = createTree(compareInts);
	int data[] = {5,10,15};
	Iterator result;
	insertIntoTree(&tree, NULL, &data[0]);
	insertIntoTree(&tree, &data[0], &data[1]);
	insertIntoTree(&tree, &data[0], &data[2]);
	result = getChildren(&tree, &data);
	ASSERT(15 == *(int*)result.next(&result));
	ASSERT(10 == *(int*)result.next(&result));
	disposeTree(&tree);
}

void test_must_insert_node_at_third_level(){
	Tree tree = createTree(compareInts);
	int data[] = {5,10,15,20};
	Iterator result;
	insertIntoTree(&tree, NULL, &data[0]);
	insertIntoTree(&tree, &data[0], &data[1]);
	insertIntoTree(&tree, &data[1], &data[2]);
	insertIntoTree(&tree, &data[1], &data[3]);
	result = getChildren(&tree, &data[1]);
	ASSERT(20 == *(int*)result.next(&result));
	ASSERT(15 == *(int*)result.next(&result));
	disposeTree(&tree);
}

void test_must_insert_nodes_at_different_levels(){
	Tree tree = createTree(compareInts);
	Iterator it;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertIntoTree(&tree, NULL, &data[0]));
	ASSERT(insertIntoTree(&tree, &data[0], &data[1]));
	ASSERT(insertIntoTree(&tree, &data[1], &data[2]));
	ASSERT(insertIntoTree(&tree, &data[2], &data[3]));
	ASSERT(insertIntoTree(&tree, &data[3], &data[4]));
	ASSERT(insertIntoTree(&tree, &data[4], &data[5]));
	disposeTree(&tree);
}
void test_must_delete_node_at_second_level(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[2] = {10,23};
	ASSERT(insertIntoTree(&tree, NULL, &data));
	ASSERT(insertIntoTree(&tree, &data, &data[1]));
	ASSERT(deleteFromTree(&tree,&data[1]));
	result = getChildren(&tree, &data);
	ASSERT(0 == result.hasNext(&result));
	disposeTree(&tree);
}
void test_must_not_delete_any_Parent_node(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[2] = {10,23};
	ASSERT(insertIntoTree(&tree, NULL, &data));
	ASSERT(insertIntoTree(&tree, &data, &data[1]));
	ASSERT(0 == deleteFromTree(&tree,&data[0]));
	disposeTree(&tree);
}
void test_must_delete_nodes_from_different_levels(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertIntoTree(&tree, NULL, &data[0]));
	ASSERT(insertIntoTree(&tree, &data[0], &data[1]));
	ASSERT(insertIntoTree(&tree, &data[1], &data[2]));
	ASSERT(insertIntoTree(&tree, &data[2], &data[3]));
	ASSERT(insertIntoTree(&tree, &data[3], &data[4]));
	ASSERT(insertIntoTree(&tree, &data[4], &data[5]));
	ASSERT(deleteFromTree(&tree, &data[5]));
	result = getChildren(&tree, &data[4]);
	ASSERT(0 == result.hasNext(&result));
	disposeTree(&tree);
}
void test_must_search_element_in_the_tree(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertIntoTree(&tree, NULL, &data[0]));
	ASSERT(insertIntoTree(&tree, &data[0], &data[1]));
	ASSERT(insertIntoTree(&tree, &data[1], &data[2]));
	ASSERT(insertIntoTree(&tree, &data[2], &data[3]));
	ASSERT(insertIntoTree(&tree, &data[3], &data[4]));
	ASSERT(insertIntoTree(&tree, &data[4], &data[5]));
	ASSERT(searchInTree(&tree,&data[4]));
	ASSERT(searchInTree(&tree,&data[2]));
	ASSERT(searchInTree(&tree,&data[0]));
	disposeTree(&tree);
}
void test_must_not_search_element_in_the_tree(){
	Tree tree = createTree(compareInts);
	Iterator result;
	int data[7] = {10,12,30,4,45,5,50};
	ASSERT(insertIntoTree(&tree, NULL, &data[0]));
	ASSERT(insertIntoTree(&tree, &data[0], &data[1]));
	ASSERT(insertIntoTree(&tree, &data[1], &data[2]));
	ASSERT(insertIntoTree(&tree, &data[2], &data[3]));
	ASSERT(insertIntoTree(&tree, &data[3], &data[4]));
	ASSERT(insertIntoTree(&tree, &data[4], &data[5]));
	ASSERT(searchInTree(&tree,&data[4]));
	ASSERT(searchInTree(&tree,&data[2]));
	ASSERT(0 == searchInTree(&tree,&data[7]));
	disposeTree(&tree);
}