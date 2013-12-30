#include "dList.h"

typedef struct tNode{
	void* data;
	struct tNode* parent;
	DoubleList children;
} TreeNode;
