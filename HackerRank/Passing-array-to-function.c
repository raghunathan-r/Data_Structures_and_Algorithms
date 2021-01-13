#include <stdio.h>
// Function prototype or declaration
void display_array (int A[], int n);
void accept_array (int A[], int n);
int main(){
    int A[5], n=5;
    // Function call
    accept_array(A, n);
    display_array(A, n);
    return 0;
}

// Function defination - You could use *A as well but for arrays A[] is used
void display_array (int A[], int n){
    printf("\nDisplaying the elemnts in the array :-\n");
    for(int i=0; i<n; i++){
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void accept_array (int A[], int n){
    printf("Enter the elements of the array :-\n");
    for(int i=0; i<n; i++){
        scanf("%d\t", A+i);
    }
}
