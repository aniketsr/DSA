#include "testUtils.h"
#include "tree.h"

// create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_insert_at_root_of_tree(){
	Tree tree = createTree();
	int a = 2;
	ASSERT(1==insertChild(&tree, &a, 0x0));
}

void test_insert_array_at_root_of_tree(){
	Tree tree = createTree();
	char a[6] = {'a','b','c','d','e','f'};
	ASSERT(1==insertChild(&tree, &a, 0x0));
}