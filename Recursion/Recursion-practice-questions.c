// Recursive function returning values
#include <stdio.h>
int fun(int n);

int main()
{
    int a = 5;
    printf("\nThe returned value of fun(a) is : %d\n\n", fun(a));
    return 0;
}

int fun(int n)
{
    if(n > 0)
    {
        return fun(n - 1) + n;
    }
}