#ifndef CIRCULAR_LIKED_LIST_H
#define CIRCULAR_LIKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;

Node* CLL_CreateNode(int Data);
void CLL_DestroyNode(Node* Node);
void CLL_AppendNode(Node** Head, Node* NewNode);
void CLL_Insert(Node* Current, Node* NewNode);
void CLL_Remove(Node** Head, Node* Remove);
Node* CLL_GetNode(Node* Head, int Location);
int CLL_CountNode(Node* Head);

#endif // !CIRCULAR_LIKED_LIST_H
