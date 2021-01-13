#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
}*Head=NULL;

void DisplayList (struct Node *p)
{
    printf("\nDisplaying the elements in circular doubly linked list :-\n");
    do
    {
        printf("%d\n", p->data);
        p=p->next;
    } while (p!=Head);   
}

void InsertNode (struct Node *p, int pos, int num)
{
    
}