#include<stdio.h>
#include<stdlib.h>

void read(int a[100][100], int r, int c);
void display(int a[100][100], int r, int c);
void transpose(int a[100][100], int r, int c);
int symm(int a[100][100], int r, int c);

int main()
{
    int a[100][100];
    int r, c;

    printf("Enter the number of rows and columns:\n");
    scanf("%d%d", &r, &c);

   if(r!=c)
   {
       printf("Not a square matrix");
       exit(0);
   }
    read(a, r, c);
    display(a, r, c);
    transpose(a, r, c);

    if (symm(a, r, c))
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");

    return 0;
}

void read(int a[100][100], int r, int c)
{
    int i, j;
    printf("Enter the elements of the matrix:\n");

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[100][100], int r, int c)
{
    int i, j;

    printf("Matrix:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void transpose(int a[100][100], int r, int c)
{
    int atran[100][100];
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            atran[j][i] = a[i][j];
        }
    }

    printf("Transpose of matrix:\n");
    display(atran, c, r);
}

int symm(int a[100][100], int r, int c)
{
    int i, j;

    if (r != c)
        return 0; // Not a square matrix, so not symmetric

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if (a[i][j] != a[j][i])
                return 0; // Elements are not symmetric
        }
    }

    return 1; // Matrix is symmetric
}
