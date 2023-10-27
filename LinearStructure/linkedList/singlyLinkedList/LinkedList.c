#include "LinkedList.h"

// SLL ��� ����
Node* SSL_CreateNode(int NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

// SLL ��� �Ҹ�
void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

// SLL ��� �߰�
void SLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

// SLL ��� Ž��
Node* SLL_GetNode(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}
	return Current;
}

// SLL ��� ����
void SLL_InsertNode(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

// SLL ��� ����
void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;

		while (Current != NULL && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}

		if (Current != NULL)
		{
			Current->NextNode = Remove->NextNode;
		}
	}
}

// SLL ��� ����
int SLL_GetNodeCount(Node* Head)
{
	int Count = 0;
	Node* Current = Head;
	
	while (Current != NULL)
	{
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}