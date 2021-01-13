#include <stdio.h>
int main()
{
    printf("\n\nThe ASCII code for 'a' : %d", 'a');
    printf("\nThe ASCII code for 'z' : %d", 'z');
    printf("\nThe ASCII code for 'A' : %d", 'A');
    printf("\nThe ASCII code for 'Z' : %d", 'Z');
    printf("\nCapitalising h : %c", 'h' + 'A' - 'a');
    printf("\nLowercase of A : %c", 'A' + 'a' - 'A');
    return 0;
}