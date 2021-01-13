#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
	int row;
	int col;
	int *M;
};

typedef struct Matrix Matrix;

void createMatrix(Matrix *mat);
void displayMatrix(Matrix *mat);

int main()
{
	Matrix A, B;
	printf("\nEnter the elments of the first matrix A 👇\n");
    createMatrix(&A);
	displayMatrix(&A);

    return 0;
}

void createMatrix(Matrix *mat)
{
	int m, n;
	printf("\nEnter the number of rows : ");
	scanf("%d", &m);
	printf("Enter the number of coloumns : ");
	scanf("%d", &n);
	mat->M = (int *)malloc(m * n * sizeof(int));
	
	printf("\nEnter the elements of the matrix :-\n");
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			scanf("%d", (mat->M + i*n + j));
			(mat->M + i*n + j) = 10 * i + j;
		}
	}
}

void displayMatrix(Matrix *mat)
{
	printf("\nDisplaying the matrix :-\n");
	for(int i=0; i<mat->row; i++)
	{
		for(int j=0; j<mat->col; j++)
		{
			printf("%d\t", *(mat->M + i * mat->col + j));
		}
		printf("\n");
	}
}