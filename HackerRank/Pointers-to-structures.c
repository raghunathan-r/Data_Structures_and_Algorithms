#include <stdio.h>
#include <stdlib.h>
struct rectangle {
    int l,b;
};

int main()
{
    // Initising and decalreing the structure
    struct rectangle a = {10, 20};
    // Decalring a pointer
    struct rectangle *p = &a;
    // Printing the values
    printf("The value of length is : %d\n", (*p).l);
    printf("The value of bredth is : %d\n", (*p).b);
    // This is usually dont using the arrow operator 
    printf("\nThe value of length is : %d\n", p->l);
    printf("The value of bredth is : %d\n", p->b);

    // Now creating an object dynamically using pointer
    printf("\nDynamic allocation of struture object in heap\n");
    struct rectangle *pd;
    pd = (struct rectangle*)malloc(sizeof(struct rectangle));
    pd->l = 10;
    pd->b = 20;
    printf("\nThe value of length is : %d\n", pd->l);
    printf("The value of bredth is : %d\n", pd->b);
    free(pd);
    pd = NULL;
    return 0;
}