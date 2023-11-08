#ifndef CIRCULAR_DOUBLY_LIKED_LIST_H
#define CIRCULAR_DOUBLY_LIKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
	struct tagNode* PrevNode;
	struct tagNode* NextNode;
} Node;

Node* CDLL_CreateNode(int Data);
void CDLL_DestroyNode(Node* Node);
void CDLL_AppendNode(Node** Head, Node* NewNode);
void CDLL_Insert(Node* Current, Node* NewNode);
void CDLL_Remove(Node** Head, Node* Remove);
Node* CDLL_GetNode(Node* Head, int Location);
int CDLL_CountNode(Node* Head);

#endif // !CIRCULAR_DOUBLY_LIKED_LIST_H
