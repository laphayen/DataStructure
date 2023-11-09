#include "ArrayStack.h"

// AS 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) *Capacity);

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

// AS 소멸
void AS_DestroyStack(ArrayStack* Stack)
{
	free(Stack->Nodes);

	free(Stack);
}

// AS Push
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data;
	Stack->Top++;
}

// AS Pop
ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = --(Stack->Top);

	return Stack->Nodes[Position].Data;
}

// AS Top
ElementType AS_Top(ArrayStack* Stack)
{
	int Position = Stack->Top - 1;

	return Stack->Nodes[Position].Data;
}

int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == 0);
}