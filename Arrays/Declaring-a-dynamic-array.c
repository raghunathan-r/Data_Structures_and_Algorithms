#include <stdio.h>
#include <stdlib.h>
int * allocate_array (int n);
void display_array (int *a, int n);

int main()
{
    int n;
    printf("\n\nEnter the size of the array : ");
    scanf("%d", &n);
    int *array = allocate_array(n);
    printf("Displaying the address of array from the main function : %p", array);
    printf("\nDisplaying the entered array :-\n");
    display_array(array, n);
    free (array);
    array = NULL;
    return 0;
}

int * allocate_array(int n)
{
    int *a;
    a = (int *)malloc(sizeof(int) * n);
    printf("Displaying the address of array from allocate function : %p\n", a);
    printf ("Enter the elements of the array :-\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nEntering into memory location %p : ", a+i);
        scanf("%d", a+i);
    }
    return a;
}

void display_array (int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}