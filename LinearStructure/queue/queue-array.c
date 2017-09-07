
#include <stdio.h>

// Å¥ Å©±â
#define SIZE 5


int front = -1, rear = -1;


int Queue[SIZE];


void push(int data)
{
	if (rear >= SIZE)
	{
		puts("OVERFLOW");
		return;
	}
	Queue[++rear] = data;
}


int pop()
{
	if (front == rear)
	{
		puts("UNDERFLOW");
		return;
	}
	front++;

}


void main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	push(60);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);
	printf(" pop : %d\n front : %d rear : %d", pop(), front, rear);

}
