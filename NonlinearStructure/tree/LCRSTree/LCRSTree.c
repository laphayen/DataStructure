#include "LCRSTree.h"

// 트리 노드 생성
LCRSNode* LCRS_CreateNode(ElementType NewData)
{
	// 노드를 자유 저장소에 할당
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));

	// 노드의 멤버를 초기화
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;

	// 생성된 노드의 주소값을 반환
	return NewNode;
}

// 트리 노드 소멸
void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

// 트리 소멸
void LCRS_DestroyTree(LCRSNode* Root)
{
	// 현재 노드의 형제 노드를 소멸
	if (Root->RightSibling != NULL)
		LCRS_DestroyTree(Root->RightSibling);
	// 현재 노드의 자식 노드를 소멸
	if (Root->LeftChild != NULL)
		LCRS_DestroyTree(Root->LeftChild);

	// 현재 노드를 소멸
	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	// 루트 노드를 소멸
	LCRS_DestroyNode(Root);
}

// 트리에 자식 노드 추가
void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	// 부모 노드의 자식 노드가 없는 경우
	if (Parent->LeftChild == NULL)
		Parent->LeftChild = Child;
	// 부모 노드의 자식 노드가 있는 경우
	else
	{
		// 부모 노드의 마지막 자식 노드를 탐색
		LCRSNode* TempNode = Parent->LeftChild;

		// 부모 노드의 마지막 자식 노드를 탐색
		while (TempNode->RightSibling != NULL)
		{
			TempNode = TempNode->RightSibling;
		}
		
		// 부모 노드의 마지막 자식 노드에 자식 노드를 추가
		TempNode->RightSibling = Child;
	}
}

// 트리 출력
void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	int i = 0;
	for (i = 0; i < Depth; i++)
		printf(" ");

	printf("%c\n", Node->Data);

	// 왼쪽 자식 노드가 있는 경우
	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);

	// 오른쪽 형제 노드가 있는 경우
	if (Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);
}