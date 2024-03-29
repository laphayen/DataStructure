#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

// 트리 데이터 타입 정의
typedef int ElementType;

// 트리 노드 구조체 정의
typedef struct BSTNode
{
    struct BSTNode* Left;   // 왼쪽 자식 노드
    struct BSTNode* Right;  // 오른쪽 자식 노드

    ElementType Data;
} BSTNode;

// 트리 함수
BSTNode* BST_CreateNode(ElementType NewData);
void BST_DestroyNode(BSTNode* Node);
void BST_DestroyTree(BSTNode* Tree);
BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target);
BSTNode* BST_SearcMinNode(BSTNode* Tree);
BSTNode* BST_SearchMaxNode(BSTNode* Tree);
void BST_InserNode(BSTNode* Tree, BSTNode *Child);
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target);
void BST_InorderPrintTree(BSTNode* Node);

#endif // !BINARY_SEARCH_TREE_H