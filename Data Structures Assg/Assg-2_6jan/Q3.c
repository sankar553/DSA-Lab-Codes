#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    // Now i need to create 2 mXn matrices
    // here m is number of users and n is number of items
    int m, n,p;
    printf("Enter size of matrix ");
    scanf("%d %d", &m, &n);
    int A[m][n], B[m][n];
    // Now i need to fill the matrices with random numbers
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 5;
            B[i][j] = rand() % 5;
        }
    }
    p=rand()%(n/20)+1;
int arr[p];

    // Let's print the matrices here 
    printf("The first matrix is:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
    printf("The second matrix is :\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", B[i][j]);
        }
        printf("\n");
    }
    // Now i need to add these two matrices and to store in matrix c 
    double C[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = (A[i][j] + B[i][j]) / 2.00;
        }
    }
    // Now i need to print the matrix C
    printf("The third matrix is: the average ratings of above two matrices\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3.2f ", C[i][j]);
        }
        printf("\n");
    }
}