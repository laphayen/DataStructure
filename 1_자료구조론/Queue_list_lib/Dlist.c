#include "Dlist.h" 
//=================================================
//  리스트 초기화 !! 
//=================================================
void init()
{	// 노드 생성 !! 
	head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));
	// 링크 연결 !! 
	head->next = tail;
	head->prev = head;
	tail->prev = head;
	tail->next = tail;
}
//=================================================
// 리스트 삽입 함수 !! 
//=================================================
void push_front(int value) //  리스트의 맨앞에 삽입 !! 
{
	insert(head, value);
}
void push_back(int value) // 리스트의 맨뒤에 삽입 !! 
{
	insert(tail->prev, value);
}
void insert(NODE * Where, int value) // Where노드 뒤에 value를 삽입  
{
	NODE * newNode = (NODE*)malloc(sizeof(NODE)); // 노드 생성 !
	newNode->data = value;
	// 링크연결 !! 
	newNode->next = Where->next;
	newNode->prev = Where;
	Where->next->prev = newNode;
	Where->next = newNode;

}
//=================================================
// 리스트 삭제 함수 !! 
//=================================================
void erase(NODE * Where) //  중간에서 삭제 !! 
{
	// 링크 해제!! 
	Where->next->prev = Where->prev;
	Where->prev->next = Where->next;
	free(Where); // 노드 삭제 
}
void pop_front() // 앞에서 삭제 !! 
{
	if (head->next != tail)
		erase(head->next);
}
void pop_back() // 뒤에서 삭제 !! 
{
	if (tail->prev != head)
		erase(tail->prev);
}


void show()
{
	NODE * p = head->next;  // head다음 노드부터 
	while (p != tail)	// tail앞의 노드 까지...
	{
		printf(" %d -->", p->data);
		p = p->next;		// 다음 노드로 이동 !! 
	}
	puts("");
}
//===================================================
//  find :  검색함수구현 ..
//  매개변수 : key값 !! 
//	리턴 :  key값에 해당하는 노드의 포인터를 리턴 !! 
//===================================================
NODE * find(int key)
{
	NODE * p = head->next;  // 

							// 연결스트의 처음에서부터 마지막까지 순회하는 코드 !! 
	while (p != tail)
	{
		if (p->data == key)
			return p; // 노드의 포인터를 리턴 !! 
		else
			p = p->next;
	}
	return NULL;
}


