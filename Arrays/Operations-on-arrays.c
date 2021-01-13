#include <stdio.h>
#include <stdlib.h>

struct Array 
{
    int *A;
    int size;
    int length;
};

void accept_array (struct Array * a);
void display_array (struct Array * a);
void append_array (struct Array * a);
void insert_element (struct Array * a);
void delete_element (struct Array * a);
void sort_array (struct Array * a);

int main()
{
    struct Array arr;
    int n;
    accept_array (&arr);
    display_array (&arr);
    append_array (&arr);
    insert_element (&arr);
    delete_element (&arr);
    sort_array (&arr);
    return 0;
}

void accept_array (struct Array * a)
{
    printf("\n\nEnter the maximun size of the array : ");
    scanf("%d", &(a->size));
    a->A = (int *)malloc(a->size * sizeof(int));
    printf("\nEnter the number of elements you want to provide : ");
    scanf("%d", &(a->length));
    printf("\nEnter the elements of the array :-\n");
    for (int i = 0; i < a->length; i++)
    {
        scanf("%d", a->A+i);
    }
}

void display_array (struct Array *a)
{
    printf("\nDisplaying the array after updating :-\n");
    for (int i = 0; i < a->length; i++)
    {
        printf("\nElement stored in address %p : ", a->A + i);
        printf("%d\t", a->A[i]);
    }
}

void append_array (struct Array *a)
{
    if(a->length < a->size)
    {
        printf("\nEnter the element you want to append to the end : ");
        scanf("%d", a->A + (a->length));
        a->length = a->length + 1;
        printf("\nThe entered number is stored in location : %p", a->A + a->length);
        display_array (a);
    }
    else
    {
        printf("\nTHE ARRAY IS FULL\n");
    }

}

void insert_element (struct Array *a)
{
    printf("\n\nEnter the position you want to store the elemnt in : ");
    int x, temp;
    scanf("%d", &x);
    x = x-1;
    if(a->length + 1 < a->size)
    {
        for (int i = a->length; i > x; i--)
        {
            a->A[i] = a->A[i-1];
        }
        printf("Enter the %dth element : ", x+1);
        scanf ("%d", a->A + x);
        a->length = a->length + 1;
        display_array (a);
    }
    else
    {
        printf("\nTHE ARRAY IS FULL\n");
    }
}

void delete_element (struct Array * a)
{
    printf("\n\nEnter the position of the elemnt to delete : ");
    int x;
    scanf("%d", &x);
    x=x;
    for(int i=x; i<a->length; i++)
    {
        a->A[i-1]=a->A[i];
    }
    a->length = a->length - 1;
    display_array (a);
}

void sort_array (struct Array * a)
{
    int temp;
    printf("\nSorting the array...\n");
    for (int i=0; i<a->length; i++)
    {
        for (int j=1; j<a->length-i; j++)
        {
            if(a->A[j]>a->A[i])
            {
                temp = a->A[i];
                a->A[i]=a->A[j];
                a->A[j]=temp;
            }
        }
    }
}