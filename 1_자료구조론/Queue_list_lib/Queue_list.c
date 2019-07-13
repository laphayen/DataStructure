//=================================================
// Queue의 구현 - Dlist lib이용 !! 
//=================================================
#include "Dlist.h"

void push_queue(int data)
{
	push_front(data);
}
void pop_queue()
{
	pop_back(); 
}
int rear()	  
{
	if (head->next == tail)
		return -1;
	else 
		return head->next->data;
}
int front()
{
	if (tail->prev == head)
		return -1;
	else
		return tail->prev->data; 
}

void main()
{
	init(); // 리스트 초기화 

	push_queue(10); 
	printf(" front : %d  rear : %d \n", front(), rear());
	push_queue(20);
	printf(" front : %d  rear : %d \n", front(), rear());
	push_queue(30);
	printf(" front : %d  rear : %d \n", front(), rear());
	push_queue(40);
	printf(" front : %d  rear : %d \n", front(), rear());
	push_queue(50);
	printf(" front : %d  rear : %d \n", front(), rear());
	pop_queue();
	printf(" front : %d  rear : %d \n", front(), rear());
	pop_queue();
	printf(" front : %d  rear : %d \n", front(), rear());
	pop_queue();
	printf(" front : %d  rear : %d \n", front(), rear());
	pop_queue();
	printf(" front : %d  rear : %d \n", front(), rear());
	pop_queue();
	printf(" front : %d  rear : %d \n", front(), rear());

}