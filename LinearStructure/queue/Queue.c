//=======================================================
// Queue (큐) :  대기열 !! 
// -> 먼저 들어간 데이타 먼저 나오는구조 ( First In First Out) 
// ->  순차적인 처리를 하기위해 사용 !! 
//   EX) 은행, 식당 번호표 
//=======================================================
// 배열을 이용한 큐의 구현 !! 
#include <stdio.h>
#define MAX 5
/* 
int front = -1, rear = -1;

int Queue[MAX]; 
 일반적인 배열을 이용한 큐의 구현 !! 
//	-->  한번 데이타를 저장하면 다시 쓸수 없다... ㅠㅠ 
//  -->  배열을 이용한다면 원형큐를 사용한다 !! 
// Queue 삽입 
void push(int data)
{
	if (rear >= MAX)
	{
		puts("Queue Overflow!!");
		return;
	}
	Queue[++rear] = data; 
}
void pop()
{
	if (front == rear)
	{
		puts("Queue underflow!!"); 
		return;
	}
	front++;

}
*/
// 개선..  배열을 이용한  원형 큐의 구현 !! 
int Queue[MAX];

int front = 0, rear = 0; 

void push(int data)
{
	if ((rear + 1) % MAX == front)
		return;
	Queue[rear] = data; 
	rear = (rear + 1) % MAX;
}

int pop()
{
	int data;
	if (front == rear)
		return -1; 
	data = Queue[front];
	front = (front + 1) % MAX;
	return data;
}

void main()
{ 
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear );
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	push(60);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	
}
