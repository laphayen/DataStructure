#ifndef LCRS_TREE_H
#define LCRS_TREE_H

#include <stdio.h>
#include <stdlib.h>

// 트리 데이터 타입 정의
typedef char ElementType;

// 트리 노드 구조체
typedef struct LCRSNode
{
	// 왼쪽 자식 노드를 가리키는 포인터
	struct LCRSNode* LeftChild;
	// 오른쪽 형제 노드를 가리키는 포인터
	struct LCRSNode* RightSibling;

	// 노드의 데이터를 저장하는 멤버
	ElementType Data;
} LCRSNode;

LCRSNode* LCRS_CreateNode(ElementType NewData);
void LCRS_DestroyNode(LCRSNode* Node);
void LCRS_DestroyTree(LCRSNode* Node);
void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode);
void LCRS_PrintTree(LCRSNode* Node, int Depth);

#endif // !LCRS_TREE_H