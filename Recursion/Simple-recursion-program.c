#include <stdio.h>
// Function prototype
void fun1(int n);
void fun2(int n);
int main()
{
    printf("\nRecursive function with print statement first :-\n");
    fun1 (3);
    printf("\n\nRecursive function with print statemnet after the clas :-\n");
    fun2 (3);
    printf("\n\n");
    return 0;
}

// Recursive function with print statement first
void fun1 (int n)
{
    if (n > 0)
    {
        printf("%d", n);
        fun1(n - 1);
    }
    
}

// Recursive function with print statemnet after the call
void fun2 (int n)
{
    if (n > 0)
    {
        fun2(n - 1);
        printf("%d", n);
    }
    
}