#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*first=NULL;

void createList (int A[], int n)
{
    struct Node *temp, *last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        temp->prev = last;
        last->next = temp;
        last = temp;
    }  
}

void DisplayList(struct Node *p)
{
    printf("\nDisplaying the list :-\n");
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p=p->next;
    }
}

int Length(struct Node *p)
{
    int len = 0;
    while(p!=NULL)
    {
        len = len + 1;
        p=p->next;
    }
    return len;
}

void InsertNode (struct Node *p, int pos, int num)
{
    struct Node *temp;
    if(pos<0 || pos>Length(p))
    {
        return;
    }
    if(pos==0)
    {
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = num;
        temp->prev = NULL;
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    else
    {
        for (int i = 1; i < pos-1; i++)
        {
            p=p->next;
        }
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = num;
        temp->prev = p;
        temp->next = p->next;
        if (p->next)    
        {
            p->next->prev = temp;
        }
        p->next = temp;
    }  
}

int DeleteNode (struct Node *p, int pos)
{
    int deletedElement;
    if (pos < 0 || pos > Length(p))
    {
        return -1;
    }
    if (pos == 1)
    {
        first = first->next;
        if (first != NULL)
        {
            first->prev = NULL;
        }
        deletedElement = p->data;
        free(p);
    }
    else
    {
        for (int i = 0; i < pos-1; i++)
        {
            p=p->next;
        }
        p->prev->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = p->prev;
        }
        deletedElement = p->data;
        free(p);
    }
    return deletedElement;   
}

int main()
{
    int A[]={1, 2, 3, 4, 5};
    createList (A, 5);
    printf("\nLength of the list is : %d\n", Length(first));
    DisplayList(first);

    DeleteNode(first, 1);
    DisplayList(first);

    return 0;
}