#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    // self refrential structure
    struct Node *next;
}*first=NULL;

void display_list (struct Node *p);
void insert_node (struct Node *p, int index, int n);
int sum_list (struct Node * p);
void max_min_element (struct Node *p);
int count_node (struct Node *p);

int main()
{
    int n;
    struct Node *ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));

    return 0;
}

void insert_node(struct Node *p, int index, int n)
{
    struct Node * temp;
    int count = count_node(p);
    if (index < 0 || index > count)
    {
        printf ("\nTHE INDEX IS NOT VALID\n");
        return ;
    }
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = n;
    if (index == 0)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

void display_list (struct Node *p)
{
    printf("\n\nDisplaying the updated list :-\n");
    while (p != NULL)
    {
        printf("%d\t", p->data);
        p = p->next;
    }   
}

int count_node (struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count = count + 1;
        p = p-> next;
    }
    return count;
    // counting using recursive function, but in terms of space its o(n), more costly
    // int count_node (struct Node *p)
    // {
    //     if (p == NULL)
    //     {
    //         return 0;
    //     }
    //     else
    //     {
    //         return count_node(p->next) + 1;
    //     }    
    // }
}

int sum_list (struct Node *p)
{
    int sum = 0;
    while (p !=NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
    // Recursive function to count sum
    // int sum_list (struct Node *p)
    // {
    //     if (p = NULL)
    //     {
    //         return 0;
    //     }
    //     else
    //     {
    //         return sum_list(p->next) + p->data;
    //     }
    // }
}

void max_min_element (struct Node *p)
{
    int max = p->data, min = p->data;
    while (p != NULL)
    {
        if(p->data > max)
        {
            max = p->data;
        }
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    printf("\n\nThe largest element is : %d\nThe smallest element is : %d\n\n", max, min);
}

void search_list (struct Node *p, int search_element)
{
    int flag = 0;
    while (p != NULL)
    {
        if(p->data == search_element)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("\nElement found\n");
    }
    else
    {
        printf("\nElemnt not found\n");
    }
    // Recursive function for the same
    // Node * search_element(struct Node *p, search_element)
    // {
    //     if (p == NULL)
    //     {
    //         return NULL;
    //     }
    //     if (p->data == search_element)
    //     {
    //         return p;
    //     }
    //     return search_element(p->next, search_element);
    // }
    // Optamising the code for better search - trasnposition
    // void search_list (struct Node *p, int search_element)
    // {
    //     int flag = 0;
    //     struct Node *q = NULL;
    //     while (p != NULL)
    //     {
    //         if(p->data == search_element)
    //         {   
    //             q->next = p->next;
    //             p->next = first;
    //             first = p;
    //             flag = 1;
    //         }
    //         q = p;
    //         p = p->next;
    //     }
    //     if (flag == 1)
    //     {
    //         printf("\nElement found\n");
    //     }
    //     else
    //     {
    //         printf("\nElemnt not found\n");
    //     }
    // }
} 