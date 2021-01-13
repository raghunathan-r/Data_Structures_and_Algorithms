#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
}*first=NULL;

void insert_node_sorted (struct Node *p, int num);

int main()
{

}


void insert_node_sorted (struct Node *p, int num)
{
    struct Node *temp, *q = NULL;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;

    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        while (p && p->data < num)
        {
            q = p;
            p = p->next;
        }
        if (p==first)
        {
            temp->next = first;
            first = temp;
        }
        else
        {
            temp->next = q->next;
            q->next = temp;
        }
    }
    
    
    if (num < p->data)
    {
        
    }
    
}