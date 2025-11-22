#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int front;
    int rear;
    int *Queue;
}Queue;

void createQueue(Queue *q, int size)
{
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->Queue = (int *)malloc(sizeof(int)*q->size);
}
int enQueue(Queue *q, int x)
{
    if(q->rear == q->size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->Queue[q->rear] = x;

    }
}

int deQueue(Queue *q)
{
    int x=-1;
    if(q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
        x = q->Queue[q->front];
    }
    return x;
}

void displayQueue(Queue *q)
{
    for(int i=q->front+1; i <= q->rear ;i++)
    {
        printf("%d\t" ,q->Queue[i]);
    }
    printf("\n");
}

void enQuene_Circular(Queue *q, int x)
{
    if((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Queue[q->rear] = x;
    }
}

int deQueue(Queue *q)
{
    int x=-1;
    if(q->front == q->rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->front = (q->front +1) % q->size;
        x = q->Queue[q->front];
    }
}
int main(void)
{
    Queue q;
    createQueue(&q,5);
    enQueue(&q,10);
    enQueue(&q,20);
    enQueue(&q,30);
    enQuene_Circular(&q,50);
    displayQueue(&q);
    printf("%d ",deQueue(&q));
    return 0;
}