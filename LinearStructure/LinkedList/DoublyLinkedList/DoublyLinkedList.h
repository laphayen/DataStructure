#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
    int Data;
    struct tagNode* PrevNode;
    struct tagNode* NextNode;
} Node;

Node* DLL_CreateNode(int NewData);
void  DLL_DestroyNode(Node* Node);
void  DLL_AppendNode(Node** Head, Node* NewNode);
void  DLL_InsertNode(Node* Current, Node* NewNode);
void  DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNode(Node* Head, int Location);
int   DLL_GetNodeCount(Node* Head);

#endif DOUBLY_LINKEDLIST_H