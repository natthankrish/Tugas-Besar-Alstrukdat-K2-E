#include "../dataStructure/PrioQueue/prioqueue.c"
#include "../dataStructure/Makanan/makanan.c"
#include "../dataStructure/Time/time.c"

int main(){
    PrioQueue pq;
    MAKANAN tmp;
    tmp.name[0] = 'h';
    tmp.name[1] = 'e';
    tmp.name[2] = 'h';
    tmp.name[3] = 'e';
    tmp.deliveryTime = MinuteToTIME(10);
    MakeEmpty(&pq, 5);
    printf("maximum element in queue : %d\n", pq.MaxEl);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");

    Enqueue(&pq, tmp);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");
    
    Enqueue(&pq, tmp);
    Enqueue(&pq, tmp);
    Enqueue(&pq, tmp);
    Enqueue(&pq, tmp);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");

    Dequeue(&pq, &tmp);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");

    Dequeue(&pq, &tmp);
    Dequeue(&pq, &tmp);
    Dequeue(&pq, &tmp);
    Dequeue(&pq, &tmp);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");

    DeAlokasi(&pq);
    MakeEmpty(&pq, 3);
    printf("maximum element in queue : %d\n", pq.MaxEl);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");

    Enqueue(&pq, tmp);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");

    Enqueue(&pq, tmp);
    Enqueue(&pq, tmp);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");

    Dequeue(&pq, &tmp);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");

    Dequeue(&pq, &tmp);
    Dequeue(&pq, &tmp);
    printf("number element in queue : %d\n", NBElmt(pq));
    printf("queue empty : %d\n", IsEmpty(pq));
    printf("queue full : %d\n", IsFull(pq));
    printf("\n");



    return 0;
}