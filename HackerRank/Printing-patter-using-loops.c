#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *a;
    int b = 10;
    // Assigning the address of b to a
    a = &b;
    // Now a had the address of b and *a points to the value stored in that address
    printf("The value of a is %d and the vaue of *a is %d\n", a, *a);
    // Allocation of memory in heap
    a = (int*)malloc(5*sizeof(int)) ;
    // After dynamic allocation of memory in the heap
    printf("The address of a is %d\n", a);
    // Assigning values to the alloted memory space
    for (int i=0; i<5; i++){
        *(a+i*sizeof(int)) = 5 * i;
    }
    // Displaying the elements that are stored in the allocated memory locatoion
    for (int i=0; i<5; i++){
        printf("%d\t", *(a+i*sizeof(int)));
    }
    return 0;
}