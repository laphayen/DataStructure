#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 원형 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} listNode;

// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
} linkedList_h;


// 공백 원형 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));	// 헤드 노드 할당
	CL->head = NULL;										// 공백 리스트이므로 NULL로 설정
	return CL;
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* CL) {
	listNode* p;
	printf(" CL = (");
	p = CL->head;
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(") \n");
}

// 첫 번째 노드 삽입 연산
void insertFirstNode(linkedList_h *CL, char *x) {
	listNode* newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));	// 삽입할 새 노드 할당
	strcpy(newNode->data, x);
	if (CL->head == NULL) {		// 원형 연결 리스트가 공백인 경우	
		CL->head = newNode;		// 새 노드를 리스트의 시작 노드로 연결
		newNode->link = newNode;
	}
	else {						// 원형 연결 리스트가 공백이 아닌 경우 	
		temp = CL->head;
		while (temp->link != CL->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;	// 마지막 노드를 첫 번째 노드인 new와 원형 연결 
		CL->head = newNode;
	}
}

// pre 뒤에 노드를 삽입하는 연산
void insertMiddleNode(linkedList_h* CL, listNode *pre, char*x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// 원형 연결 리스트의 pre 뒤에 있는 노드 old를 삭제하는 연산
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;					// 삭제할 노드의 선행자 노드를 나타내는 포인터	
	if (CL->head == NULL) return;	// 공백 리스트인 경우, 삭제 연산 중단	
	if (CL->head->link == NULL) {	// 리스트에 노드가 한 개만 있는 경우
		free(CL->head);				// 첫 번째 노드의 메모리를 해제하고
		CL->head = NULL;				// 리스트 시작 포인터를 NULL로 설정
		return;
	}
	else if (old == NULL) return;   // 삭제할 노드가 없는 경우, 삭제 연산 중단	
	else {
		pre = CL->head;				// 포인터 pre를 리스트의 시작 노드에 연결		
		while (pre->link != old) {
			pre = pre->link;			// 선행자 노드를 포인터 pre를 이용해 찾음
		}
		pre->link = old->link;
		if (old == CL->head)
			CL->head = old->link;
		free(old);					// 삭제 노드의 메모리를 해제	 		
	}
}

// 원형 연결 리스트에서 x 노드를 탐색하는 연산
listNode* searchNode(linkedList_h* CL, char* x) {
	listNode *temp;
	temp = CL->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}

int main() {
	linkedList_h* CL;
	listNode *p;
	CL = createLinkedList_h();		// 공백 원형 연결 리스트 생성
	printf("(1) 원형 연결 리스트 생성하기! \n");
	

	printf("(2) 원형 연결 리스트에 [월] 노드 삽입하기! \n");
	insertFirstNode(CL, "월");
	printList(CL); getchar();

	printf("(3) 원형 연결 리스트의 [월] 노드 뒤에 [수] 노드 삽입하기! \n");
	p = searchNode(CL, "월"); insertMiddleNode(CL, p, "수");
	printList(CL); getchar();

	printf("(4) 원형 연결 리스트의 [수] 노드 뒤에 [금] 노드 삽입하기! \n");
	p = searchNode(CL, "수"); insertMiddleNode(CL, p, "금");
	printList(CL); getchar();

	printf("(5) 원형 연결 리스트에서 [수] 노드 삭제하기! \n");
	p = searchNode(CL, "수");  deleteNode(CL, p);
	printList(CL); getchar();

	return 0;
}