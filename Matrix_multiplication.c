#include<stdio.h>
#include<string.h>
void ShowMatrix(int r1,int c1, int mat[r1][c1])
{
    int i,j;
    for(i = 0; i < r1; i++)
    {
        for(j = 0; j< c1; j++)
        printf("%10d", mat[i][j]);
        printf("\n");
    }
}
int main()
{
    int row1, col1, row2, col2;
    scanf("%d %d %d %d", &row1, &col1, &row2, &col2);
    if(col1 != row2)
    {
        printf("Column 1 and Row 2 are not equal.\n");
        return;
    }
    int mat1[row1][col1], mat2[row2][col2], mat3[row1][col2];
    int i,j,k;

    for(i = 0; i < row1; i++)
        for(j = 0; j< col1; j++)
            scanf("%d", &mat1[i][j]);

    for(i = 0; i < row2; i++)
        for(j = 0; j< col2; j++)
            scanf("%d", &mat2[i][j]);
    printf("Matrix A:\n");
    ShowMatrix(row1,col1,mat1);
    printf("\n\nMatrix B:\n");
    ShowMatrix(row2,col2,mat2);
    printf("\n\nMatrix C = Matrix A * Matrix B:\n");
    for(i = 0; i < row1; i++)
    {
        for(k = 0; k< col2; k++)
        {
            mat3[i][k] = 0;
            for(j = 0; j < col1/*row2*/; j++)
                mat3[i][k] += mat1[i][j] * mat2[j][k];
        }
    }
    ShowMatrix(row1,col2,mat3);

}
