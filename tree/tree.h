#include "../linked-list/iterator.h"
typedef int comparator(void* compareWith, void *toCompare);

typedef struct{
	void* root;
	comparator* compare;
}Tree;

typedef struct treeNode{
	void* data;
	struct treeNode* parent;
	List* children;
}treeNode;

Tree createTree();
int insertChild(Tree* tree, void* data, void* parentName);
int deleteChild(Tree* tree, void* data, void* parentName);
void* getChildren(Tree tree, void* data, List* list);