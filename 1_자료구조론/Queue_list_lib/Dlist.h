//============================


#pragma once
// 구조체 선언 
// 함수 선언 
// #define  
//  -->  프로그램작성에 필요한 선언들을 미리 해두는곳 !! 
//=================================================
#include <stdio.h> 
#include <malloc.h> 
#include <stdlib.h>	

typedef struct node
{
	int data;
	struct node * next;	 // 다음 노드 
	struct node * prev; // 이전 노드 
}NODE;
//=================================================
// head , tail 포인터 전역 선언 !! 
NODE * head ;
NODE * tail ;
// 삽입 함수 
void push_back(int value);
void push_front(int value);
void insert(NODE * Where, int value);
// 삭제 함수 
void erase(NODE * Where);
void pop_front(); 
void pop_back(); 

void init(); 

void show(); 

NODE * find(int key);