#define NULL 0x0
#include <stdlib.h>
#include "iterator.h"
List list;

Tree createTree(){
	Tree tree = {NULL};
	return tree;
}

treeNode* createTreeNode(treeNode* parent, treeNode* child, void* data){
	treeNode* pTreeNode = calloc(1,sizeof(treeNode));
	List* list;
	list = create();
	pTreeNode->children = list;
	pTreeNode->parent = parent;
	pTreeNode->data = data;
	return pTreeNode;
};

treeIterator* createTreeIterator(){
	treeIterator* iterate;
	iterate->current = NULL;
	iterate->index = 0;
	iterate->tree = NULL;
	return iterate;
}

int insertAtRoot(Tree *treePtr, void *dataToInsert){
    List* list;
    treeNode* rootNode;
    list = create();
    treePtr->root = list;
    rootNode = malloc(sizeof(treeNode));
    rootNode->children = list;
    rootNode->parent = NULL;
    rootNode->data = dataToInsert;
    insert(list, 0, rootNode);
    return 1;
};

int hasTreeNext(treeIterator* it){
	return it->index < it->current->children->length;
}

treeNode* Next(treeIterator *it){
	treeNode* pTreeNode = createTreeNode(NULL, NULL, NULL);
	Iterator* internalIterator;
	Node *node;
	int i;
	List *list,*temp;
	list = (List*)it->tree->root;
	internalIterator = getIterator(list);
	if (it->current == NULL){
		while(hasNext(internalIterator)){
			node = (Node*)next(internalIterator);
			insert(temp, i, (treeNode*)node->data);
			i++;
		}
			
	// if (it->list == NULL || it ==NULL) return pTreeNode;
	// if (it->index == 0){
	// 	it->current = (Node*)it->list->head;
	// 	it->index++;
	// 	node = (Node*)getElement(it->list, 0);
	// 	pTreeNode = (treeNode*)node->data;
	// 	for (i = 0; i < pTreeNode->children->length; ++i){
	// 		temp = (Node*)getElement(pTreeNode->children,i);
	// 		insert(list, i, (treeNode*)temp->data);
	// 	}
	// 	return pTreeNode;
	// }
	// return pTreeNode;	
	}
}

int insertChild(Tree* treePtr, void *parentData, void *dataToInsert){
   	int result;
   	treeIterator *pTreeIterator;
   	treeNode* pTreeNode;
    if(NULL == parentData) return insertAtRoot(treePtr, dataToInsert);
    pTreeIterator = createTreeIterator();
    pTreeIterator = getTreeIterator(treePtr);
    while(hasTreeNext(pTreeIterator)){
    	result = treePtr->compare(Next(pTreeIterator),parentData);
    }
    return 1;
};

treeIterator* getTreeIterator(Tree *tree){
	treeIterator* iterator = createTreeIterator();
	iterator->current = (treeNode*)tree->root;
	iterator->tree = tree;
	return iterator;
}