#include <stdio.h>
void display_array (int a[], int n);

int main ()
{
    int a[5], n=5;
    printf("\n\nDisplaying array after \"int a[5]\" : \n");
    display_array (a, n);

    int b[5] = {1,2,3,4,5};
    printf("\n\nDisplaying array after \"b[5] = {1,2,3,4,5}\" : \n");
    display_array (b, n);

    int c[5] = {1,2};
    printf("\n\nDisplaying array after \"c[5] = {1,2}\" : \n");
    display_array (c, n);

    int d[5] = {0};
    printf("\n\nDisplaying array after \"d[5] = {0}\" : \n");
    display_array (d, n);

    int e[] = {1,2,3,4,5,6,7,8,9};
    printf("\n\nDisplaying array after \"e[] = {1,2,3,4,5,6,7,8,9}\" : \n");
    display_array (e, sizeof(e)/4);
    return 0;
}

void display_array (int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // Diffrent ways of printing an array
        // printf("%d\t", i[a]);
        // printf("%d\t", *(a+i));
        printf("%d\t", a[i]);
    } 
}