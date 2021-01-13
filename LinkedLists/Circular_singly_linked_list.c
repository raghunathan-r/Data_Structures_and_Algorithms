// Singly circular linked lists
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Head;

void createCircularList(int A[], int n)
{
    struct Node *temp, *last;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    
    for (int i = 1; i < n; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    } 
}

void displayCircularList(struct Node *p)
{
    printf("Displaying updated list :-\n");
    do
    {
        printf("%d\n", p->data);
        p=p->next;   
    }while (p!=Head);
}

// Recursicive function for displaying elements in circular list
/*void diplayCircularListRecursive(struct Node *p)
{
    // static is used to have only one copy of flag that is acceable within the function
    static int flag = 0;
    if (p!=head || flag==0)
    {
        flag=1;
        printf("%d\n", p->data);
        diplayCircularListRecursive(p);
    }
    flag = 0;
}*/

void insertNodeAtBeggining (struct Node *p, int num)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = Head;
    while (p->next!=Head)
    {
        p=p->next;
    }
    p->next = temp;
    Head = temp;
}

int Length (struct Node *p)
{
    int len=0;
    do
    {
        len = len + 1;
        p = p->next;
    }while(p!=Head);
    return len;
}

void insertNode (struct Node *p, int pos, int num)
{
    struct Node *temp;
    if (pos < 0 || pos > Length(Head))
    {
        printf("\nINVALID INPUT !\n");
        return;
    }
    
    if(pos==0)
    {
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data = num;
        if (Head==NULL)
        {
            Head = temp;
            Head->next = temp;
        }
        else
        {
            while (p->next != Head)
            {
                p=p->next;
            }
            p->next = temp;
            temp->next = Head;
            Head = temp;
        }
    }
    else
    {
        for (int i = 0; i < pos-1; i++)
        {
            p = p->next;
        }
        
    }
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = p->next;
    p->next = temp; 
}

int deleteNodeAtPosition (struct Node *p, int pos)
{
    int deletedElement;
    struct Node *q;
    if (pos < 0 || pos > Length(Head))  
    {
        return -1;
    }
    if (pos == 1)
    {
        while(p->next != Head)
        {
            p = p->next;
        }
        deletedElement = Head->data;
        if (Head==p)
        {
            free(Head);
            Head = NULL;
        }
        else
        {
            p->next = Head->next;
            free(Head);
            Head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < pos-2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        deletedElement = q->data;
        free(q);
    }
    return deletedElement;    
}


int main()
{
    int A[] = {2,3,4,5,6};
    createCircularList(A, 5);
    displayCircularList(Head);

    deleteNodeAtPosition (Head, 1);
    displayCircularList(Head);

    return 0;
}