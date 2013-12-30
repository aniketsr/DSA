#include "treeIterator.h"
#include "iterator.h"
#include "dList.h"


#ifndef _COMPARE_
#define _COMPARE_

typedef int (*Compare)(void* first, void* second);
#endif
typedef struct {
	Compare cmp;
	void *root;
} Tree;

typedef struct tNode{
	void* data;
	struct tNode* parent;
	DoubleList children;
} TreeNode;


Tree createTree(Compare cmp);
int insertIntoTree(Tree* tree, void* parentData, void* data);
Iterator getChildren(Tree* tree, void* parentData);
int deleteFromTree(Tree* tree, void* data);
int searchInTree(Tree* tree, void* data);
void disposeTree(Tree* tree);