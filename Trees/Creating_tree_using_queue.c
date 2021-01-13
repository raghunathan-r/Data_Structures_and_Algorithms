#include <stdio.h>
#include <stdlib.h>

struct Node  // Tree node structure
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q; // An array that stores pointers of type nodes
};

void create (struct Queue *q, int size);
void enqueue (struct Queue *q, int num);
int dequeue (struct Queue *q);
int isEmpty (struct Queue q);
void treeCreate();
void preorder (struct Node *p);

int main()
{
    treeCreate();
    preorder(root);
    return 0;
}


void create (struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node*));
}

void enqueue (struct Queue *q, Node *num)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is FULL\n");
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = num;
    }  
}

Node* dequeue (struct Queue *q)
{
    Node *deletedElement = NULL;
    if (q->front == q->rear)
    {
        printf("Queue is EMPTY\n");
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        deletedElement = q->Q[q->front];
    }
    return deletedElement;
}

int isEmpty (struct Queue q)
{
    return q.front == q.rear;
}

void treeCreate() // this is for creating a tree
{
    struct Node *p, *t;
    int num;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value : ");
    scanf("%d", &num);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = num;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while(!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child : ");
        scanf("%d", &num);
        if (num != -1) // if num = -1 we assume no element is stored there 
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = num;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child : ");
        scanf("%d", &num);
        if (num != -1) // if num = -1 we assume no element is stored there 
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = num;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder (struct Node *p)
{
    if (p)
    {
        printf("%d\t", p->data);
        preorder (p->lchild);
        preorder (p->rchild);
    }   
}