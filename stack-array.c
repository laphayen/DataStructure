
#include <stdio.h>


#define MAX 3


int stack[MAX];


int top = -1;


void push(int data)
{
	if (top >= MAX - 1)
	{
		puts("OVERFLOW");
	}
	else
	{
		stack[++top] = data;
	}
}


void pop()
{
	if (top <= -1)
	{
		puts("UNDERFLOW");
	}
	else
	{
		top--;
	}
}


void main()
{
	push(1);
	printf("top : %d \n", stack[top]);
	push(2);
	printf("top : %d \n", stack[top]);
	push(3);
	printf("top : %d \n", stack[top]);
	push(4);
	printf("top : %d \n", stack[top]);
	pop();
	printf("top : %d \n", stack[top]);
	pop();
	printf("top : %d \n", stack[top]);
	pop();
	printf("top : %d \n", stack[top]);
	pop();
	printf("top : %d \n", stack[top]);
}
