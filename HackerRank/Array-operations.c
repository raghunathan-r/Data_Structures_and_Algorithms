#include <stdio.h>
int array_inputs (int a[]);
void array_display (int a[], int n);
int main()
{
    int array[10], n;
    n = array_inputs (array);
    array_display (array, n);  

}

int array_inputs (int a[])
{
    int n;
    printf("\n\nEnter the number of elements you wnat to provide [must be less than 10] : ");
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)     
    {
        scanf("%d", &a[i]);
    }
    return n;
}

void array_display (int a[], int n)
{
    printf("\nDisplaying the entered elemnts :-\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n\n");
}