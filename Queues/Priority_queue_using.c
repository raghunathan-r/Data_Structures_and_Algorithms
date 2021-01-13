#include<stdio.h>
#include<stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void createQueue (struct Queue *q);
void enqueue (struct Queue *q, int num);
void checkPreioruty(struct Queue *q, int num);
void dequeue (struct Queue *q, int num);
void display (struct Queue q);

int main()
{
    int ch, num;
    struct Queue q;
    createQueue(&q);
    printf("\n1. Add element\n2. Delete element\n3. Display queue\n4. Exit\n\n");
    
    do
    {
        printf("\nEnter the option corresponding to your desired choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                {
                    printf("Enter the element to be added : ");
                    scanf("%d", &num);
                    enqueue(&q, num);
                    break;
                }
            case 2:
                {
                    printf("Enter the element to be deleted : ");
                    scanf("%d", &num);
                    dequeue(&q, num);
                    break;
                }
            case 3:
                {
                    display(q);
                    break;
                }
            case 4:
                {
                    printf("Thank you\n\n");
                    return 0;
                }
            default:
                printf("INVALID INPUT TRY AGAIN\n");
                break;
        }        
    } while (ch != 4);
}
void createQueue (struct Queue *q)
{
    printf("\nEnter the size of the queue : ");
    scanf("%d", &(q->size)); 
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = -1;    
}

void enqueue (struct Queue *q, int num)
{
    if (q->rear >= q->size -1)
    {
        printf("Queue is FULL\n");
        return;
    }
    if ((q->front == -1) && (q->rear == -1))
    {
        q->front = q->front + 1;
        q->rear = q->rear + 1;
        q->Q[q->rear] = num;
        return;
    }
    else
    {
        checkPreioruty(q, num);
    }
    q->rear = q->rear + 1;
}

void checkPreioruty(struct Queue *q, int num)
{
    int i;
    for (i = 0; i <= q->rear; i++)
    {
        if (num >= q->Q[i])
        {
            for (int j = q->rear + 1; j > i; j--)
            {
                q->Q[j] = q->Q[j - 1];
            }
            q->Q[i] = num;
            return;
        }
    }
    q->Q[i] = num;
}

void dequeue (struct Queue *q, int num)
{
    if ((q->front == -1) && (q->rear == -1))
    {
        printf("Queue is EMPTY\n");
        return;
    }
    printf("Deleting %d from the queue...\n", num);
    for (int i = 0; i <= q->rear; i++)
    {
        if (num == q->Q[i])
        {
            for (; i < q->rear; i++)
            {
                q->Q[i] = q->Q[i + 1];
            }
            q->Q[i] = -99;
            q->rear = q->rear - 1;
            if (q->rear == -1)
            {
                q->front = -1;
            }
            return;
        }
    }
    printf("Unable to delete %d from queue as its not found\n", num);
}

void display(struct Queue q)
{
    printf("Displaying the queue :-\n");
    if ((q.front == -1) && (q.rear == -1))
    {
        printf("Queue is EMPTY\n");
        return;
    }
    while (q.front <= q.rear)
    {
        printf("%d\t", q.Q[q.front]);
        q.front = q.front + 1;
    }
    printf("\n");
}