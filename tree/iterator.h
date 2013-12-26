#include "tree.h"
typedef struct {
	struct treeNode* current;
	Tree* tree;
	int index;
} treeIterator;

treeIterator* getTreeIterator(Tree *tree);
Node* treeNext(treeIterator* it);
int treeHasNext(treeIterator* it);