#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*Top=NULL;

void Push(int num)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    if (temp == NULL)
    {
        printf("STACK OVERFLOW!\n");
    }
    else
    {
        temp->data = num;
        temp->next = Top;
        Top = temp;
    }   
}

int Pop()
{   
    // If Function return -1 the stack in empty
    int deletedElement;
    struct Node *temp;
    if(temp == NULL)
    {
        printf("STACK IS EMPTY!\n");
    }
    else
    {
        temp = Top;
        Top = Top->next;
        deletedElement = temp->data;
        free(temp);
    }
    return deletedElement;
}

int Peek(int pos)
{
    struct Node *p = Top;
    int element = -1;
    for (int i = 0; i < pos-1 && p!=NULL ; i++)
    {
        p = p->next;
    }
    if(p!=NULL)
    {
        return p->data;
    }
    else
    {
        return -1;  
    }   
}

int StackTop ()
{
    if(Top!=NULL)
    {
        return Top->data;
    }
    else
    {
        return -1;
    }
}

int IsEmpyt ()
{
    if(Top!=NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int IsFull ()
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp != NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    free(temp);
}

void Display()
{
    struct Node *p;
    p = Top;
    printf("\nDisplaying the elements in the stack :-\n");
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    Push(10);
    Push(20);
    Push(30);

    Display();

    printf("\nPoped element : %d\n", Pop());
    Display();

    return 0;
}