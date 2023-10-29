#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int Data;
	struct tagNode* NextNode;
} Node;

Node* SSL_CreateNode(int NewData);
void SSL_DestroyNode(Node* Node);
void SSL_AppendNode(Node** Head, Node* NewNode);
void SLL_InsertNode(Node* Current, Node* NewNode);
void SSL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNode(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);

#endif LINKEDLIST_H