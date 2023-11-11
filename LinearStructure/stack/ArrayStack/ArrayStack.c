#include "ArrayStack.h"

// AS 생성
void AS_CreateStack(ArrayStack** Stack, int Capacity)
{
	// 스택을 자유 저장소에 할당
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	
	// 스택 용량만큼 노드를 자유 저장소에 할당
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) *Capacity);

	// 스택 용량과 Top 초기화
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}

// AS 소멸
void AS_DestroyStack(ArrayStack* Stack)
{
	// 배열 스택 노드를 자유 저장소에서 해제
	free(Stack->Nodes);

	// 배열 스택을 자유 저장소에서 해제
	free(Stack);
}

// AS 데이터 삽입
void AS_Push(ArrayStack* Stack, ElementType Data)
{
	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data;
	Stack->Top++;
}

// AS 데이터 제거
ElementType AS_Pop(ArrayStack* Stack)
{
	int Position = --(Stack->Top);

	return Stack->Nodes[Position].Data;
}

// AS 맨 위 데이터 반환
ElementType AS_Top(ArrayStack* Stack)
{
	int Position = Stack->Top - 1;

	if (AS_IsEmpty(Stack))
	{
		printf("Stack is Empty\n");
		exit(-1);
	}
	
	return Stack->Nodes[Position].Data;
}

// AS 크기 반환
int AS_GetSize(ArrayStack* Stack)
{
	return Stack->Top;
}

// AS 비어있는지 여부
int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == 0);
}