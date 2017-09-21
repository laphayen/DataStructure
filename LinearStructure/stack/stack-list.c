
#include <stdio.h>


#include <malloc.h>


typedef struct node
{
	int data;
	struct node * next;
	struct node * prev;
}NODE;


NODE *head, *tail;


void push(int data)
{
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->next = head->next;
	newNode->prev = head;
	head->next->prev = newNode;
	head->next = newNode;
}


void pop()
{
	if (head->next == tail)
	{
		puts("stack underflow !! ");
		return;
	}
	NODE * del = head->next;

	del->next->prev = del->prev;
	del->prev->next = del->next;
	free(del);
}


void top()
{
	if (head->next != tail)
		printf(" top : %d\n", head->next->data);
}


void main()
{
head = (NODE*)malloc(sizeof(NODE));
	tail = (NODE*)malloc(sizeof(NODE));
	head->next = tail;
	tail->prev = head; 

	push(10); 
	top();
	push(20);
	top();
	push(30);
	top();
	push(40);
	top(); 
	pop();
	top();

	pop();
	top();
	pop();
	top();
	pop();
	top();
	pop();
	top();
}
