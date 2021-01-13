#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*first=NULL;

void createLinkedList (int A[], int n)
{
    int i;
    struct Node *temp, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void displayLinkedList (struct Node *p)
{
    printf("\nDisplaying the elements of the list :-\n");
    while (p!=NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }
}

void SortLinkedList (struct Node *p)
{
    struct Node *q;
    for ( ; p->next != NULL ; p = p->next)
    {
        for (q=p->next ; q!=NULL; q = q->next)
        {
            if (p->data > q->data)
            {
                int temp= p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

int main()
{
    int A[10];
    printf("Enter the 10 elements you want to store in the linked list :-\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", A+i);
    }
    createLinkedList (A, 10);
    displayLinkedList (first);
    
    printf("\n\nSorting the linked list...\n");
    SortLinkedList(first);
    displayLinkedList(first);
    return 0;
}