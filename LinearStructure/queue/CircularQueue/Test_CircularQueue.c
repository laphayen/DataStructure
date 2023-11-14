#include "CircularQueue.h"

int main(void)
{
    CircularQueue* Queue;

    CQ_CreateQueue(&Queue, 5);

    CQ_Enqueue(Queue, 1);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    CQ_Enqueue(Queue, 2);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    CQ_Enqueue(Queue, 3);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    CQ_Enqueue(Queue, 4);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    CQ_Enqueue(Queue, 5);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    printf("%d \n", CQ_IsFull(Queue));

    CQ_Dequeue(Queue);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    CQ_Dequeue(Queue);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));

    CQ_Dequeue(Queue);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    
    CQ_Enqueue(Queue, 6);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    CQ_Enqueue(Queue, 7);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    CQ_Enqueue(Queue, 8);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));
    printf("%d \n", CQ_IsFull(Queue));
    CQ_Enqueue(Queue, 9);
    printf("Capcatity: %d, size: %d\n", Queue->Capacity, CQ_GetSize(Queue));

    CQ_Dequeue(Queue);

    return 0;
}