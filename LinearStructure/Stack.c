//==============================================================
//  stack ( 스택) 
//	 - 나중에 들어오 데이타가 먼저 나가는 구조  (Last In First Out) 
//	 - 먼저 들어온 데이타가 나중에 나가는구조  
//	 - 입구가 1개여서 들어온쪽으로만 삽입 삭제가 가능  
//	 ex)  택시 동전통, 탄창 
//
//==============================================================
// 스택의 구현 (배열) 
//==============================================================
#include <stdio.h> 
#define MAX 3

int stack_array[MAX];
int top = -1;         
// 스택에 값을 삽입 !! 
void push(int data)
{
	if (top >= MAX - 1)
		puts("stack overflow !!");
	else
		stack_array[++top] = data;
}
void pop()
{
	if (top <= -1)
		puts("stack underflow!!");
	else

		top--;
}

void main()
{
	push(10); 
	printf("top : %d \n", stack_array[top]);
	push(20);
	printf("top : %d \n", stack_array[top]);
	push(30);
	printf("top : %d \n", stack_array[top]);
	push(40);
	printf("top : %d \n", stack_array[top]);
	pop();
	printf("top : %d \n", stack_array[top]);
	pop();
	printf("top : %d \n", stack_array[top]);
	pop();
	printf("top : %d \n", stack_array[top]);
	pop();
	printf("top : %d \n", stack_array[top]);

}
