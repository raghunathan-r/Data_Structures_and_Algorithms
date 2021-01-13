#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void createStack (struct Stack *sta);
void displayStack (struct Stack sta);
int isEmpty (struct Stack sta);
int isFull (struct Stack sta);
void push (struct Stack *sta, int num);
int pop (struct Stack *sta);
int peek (struct Stack sta, int pos);

int main()
{
    struct Stack st;
    int choice;
    createStack (&st);
    do
    {   
        printf("\n\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n\n");
        printf("Enter the number corrspondind to the desired choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            {
                int num;
                printf("Enter the elemnt to push : ");
                scanf("%d", &num);
                push (&st, num);
                break;
            }
        case 2:
            {
                printf("\n\nElement poped : %d", pop(&st));
                break;
            }
        case 3:
            {
                int pos;
                printf("\n\nEnter the position of the element to display : ");
                scanf ("%d", &pos);
                printf("\nThe element in position %d is : %d\n", pos, peek(st, pos));
                break;
            }
        case 4:
            {
                displayStack (st);
                break;
            }
        case 5:
            {
                printf("\nTHANK YOU\n\n");
                return 0;
            }
        default:
            printf("\nINVALID INPUT, TRY AGAIN\n");
            break;
        }
        
    } while (choice != 5);
}

void createStack (struct Stack *sta)
{
    printf("Enter the maximum size of stack : ");
    scanf("%d", &(sta->size));
    // Allocating the memory for stack array
    sta->s = (int *)malloc(sta->size * sizeof(int));
    sta->top = -1;
}

void displayStack (struct Stack sta)
{   
    if(isEmpty(sta))
    {
        printf("\nStack is Empty\n");
    }
    else
    {
        printf("\n\nDisplaying the updated stack :-\n");
        for(int i = sta.top ; i>= 0; i--)
        {
            printf("%d\n", sta.s[i]);
        }   
    }
}

int isEmpty (struct Stack sta)
{
    if (sta.top == -1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

int isFull (struct Stack sta)
{
    if (sta.top == sta.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push (struct Stack *sta, int num)
{
    if (sta->top == sta->size -1)
    {
        printf("\n\nStack Overflow\n");
    }
    else
    {
        sta->top = sta->top + 1;
        sta->s[sta->top] = num;
    } 
}

int pop (struct Stack *sta)
{
    int x = -1;
    if(sta->top == -1)
    {
        printf("\n\nStack Underflow\n");
        return -1;
    }
    else
    {
        x = sta->top;
        sta->top = sta->top -1;
        return x;
    }
}

int peek (struct Stack sta, int pos)
{
    // If function returns -1 the value is not found
    int x = -1;
    if((sta.top - pos + 1) < 0)
    {
        printf("\n\nInvalid Position\n");
    }
    else
    {
        x = sta.s[(sta.top - pos) + 1];
        return x;
    }
    
}

int stackTop (struct Stack sta)
{
    if (sta.top == -1)
    {   
        return -1;
    }
    else
    {
        return sta.s[sta.top];
    } 
}