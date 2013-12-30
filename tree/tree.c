#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

Tree createTree(Compare cmp){
	Tree tree = {cmp,NULL};
	return tree;
}

TreeNode* createTreeNode(void *data,TreeNode *parent){
	TreeNode *treeNode = malloc(sizeof(TreeNode));
	treeNode->data = data;
	treeNode->parent = parent;
	treeNode->children = create();
	return treeNode;
}

TreeNode* getTreeNode(DoubleList list,void *dataToFind,Compare cmp){
	Iterator it = getIterator(&list);
	TreeNode *tNode;
	while(it.hasNext(&it)){
		tNode = (TreeNode*)it.next(&it);
		if(0 == cmp(tNode->data,dataToFind))
			return tNode;
		if(tNode->children.head)
			return getTreeNode(tNode->children, dataToFind, cmp);
	}
	return NULL;
}

int insertIntoTree(Tree* tree, void* parentData, void* childData){
	TreeNode *root = (TreeNode*)tree->root;
	TreeNode *nodeToInsert, *parentNode;
	if(NULL == tree->root){
		tree->root = createTreeNode(childData, NULL);
		return 1;
	}
	if(0 == tree->cmp(root->data,parentData)){
		parentNode = root;
		nodeToInsert = createTreeNode(childData, parentNode);
		insert(&root->children, 0, nodeToInsert);
		return 1;
	}
	parentNode = getTreeNode(root->children, parentData, tree->cmp);
	nodeToInsert = createTreeNode(childData, parentNode);
	insert(&parentNode->children, 0, nodeToInsert);
	return 1;
}

void* treeNext(Iterator *it){
	TreeNode *node;
	Iterator treeIterator = getIterator(it->list);
	treeIterator.position = it->position;
	node = treeIterator.next(&treeIterator);
	it->position++;
	return node->data;
}

Iterator getChildren(Tree* tree, void *parent){
	TreeNode *tNode;
	TreeNode *root = (TreeNode*)tree->root;
	Iterator it;
	if(0 == tree->cmp(root->data,parent))
		tNode = root;
	else 
		tNode = getTreeNode(root->children, parent, tree->cmp);
	it = getIterator(&tNode->children);
	it.next = &treeNext;
	return it;
}

int deleteFromTree(Tree *tree, void *data){
	TreeNode *root = (TreeNode*)tree->root;
	TreeNode *tNode,*parent;
	Iterator it;
	tNode = getTreeNode(root->children, data, tree->cmp);
	if(tNode == NULL) return 0;
	if(0 == tNode->children.length){
		parent = tNode->parent;
		it = getIterator(&parent->children);
		while(it.hasNext(&it)){
			if(tree->cmp(data,it.next(&it)))
				break;
		}
		delete(&parent->children, it.position - 1);
		return 1;
	}
	return 0;
}

int searchInTree(Tree* tree, void* searchElement){
    TreeNode* root = (TreeNode*)(tree->root);
    if(0 == tree->cmp(searchElement,root->data))
    	return 1;
    if(NULL != getTreeNode(root->children,searchElement,tree->cmp))
        return 1;
    return 0;
}

void disposeTree(Tree* tree){
	free(tree->root);
}