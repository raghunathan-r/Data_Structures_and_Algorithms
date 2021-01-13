#include <stdio.h>
struct rectangle
{
    int length, bredth;
};
// Function prototypes
void assign_value (struct rectangle *r, int l, int b);
void change_length (struct rectangle *r, int l);
int find_area (struct rectangle r);
int main()
{
    struct rectangle rect;
    // Function call to assign values
    assign_value (&rect, 10, 20);
    printf("\nThe initial area : %d\n", find_area(rect));
    change_length (&rect, 30);
    printf("Area after changing length : %d\n\n", find_area(rect));
    return 0;
}

// Function definations
void assign_value (struct rectangle *r, int l, int b)
{
    r->length = l;
    r-> bredth = b;
}

void change_length (struct rectangle *r, int l)
{
    r->length = l;
}

int find_area (struct rectangle r)
{
    return r.length * r.bredth;
}