#include <bits/stdc++.h>
using namespace std;

int rows, cols;
int mat[2000][2000];

void mergeRowWise(int row, int colStart, int colEnd)
{
    int mid = (colStart + colEnd) / 2 + 1;
    int left[mid - colStart];
    int right[colEnd - mid + 1];
    int k1 = 0, k2 = 0;
    for (int i = colStart; i <= colEnd; i++)
        if (i < mid)
            left[k1++] = mat[row][i];
        else
            right[k2++] = mat[row][i];

    int j1 = 0, j2 = 0;
    while (j1 < k1 && j2 < k2)
        if (left[j1] < right[j2])
            mat[row][colStart++] = left[j1++];
        else
            mat[row][colStart++] = right[j2++];
    while (j1 < k1)
        mat[row][colStart++] = left[j1++];
    while (j2 < k2)
        mat[row][colStart++] = right[j2++];
}
void mergeColumnWise(int col, int rowStart, int rowEnd)
{
    int mid = (rowStart + rowEnd) / 2 + 1;
    int up[mid - rowStart];
    int down[rowEnd - mid + 1];
    int k1 = 0, k2 = 0;
    for (int i = rowStart; i <= rowEnd; i++)
        if (i < mid)
            up[k1++] = mat[i][col];
        else
            down[k2++] = mat[i][col];

    int j1 = 0, j2 = 0;
    while (j1 < k1 && j2 < k2)
        if (up[j1] < down[j2])
            mat[rowStart++][col] = up[j1++];
        else
            mat[rowStart++][col] = down[j2++];

    while (j1 < k1)
        mat[rowStart++][col] = up[j1++];
    while (j2 < k2)
        mat[rowStart++][col] = down[j2++];
}

void Merge(int rowStart, int rowEnd, int colStart, int colEnd)
{
    for (int i = rowStart; i <= rowEnd; i++)
        mergeRowWise(i, colStart, colEnd);

    for (int i = colStart; i <= colEnd; i++)
        mergeColumnWise(i, rowStart, rowEnd);
}

void Divide(int rowStart, int rowEnd, int colStart, int colEnd)
{
    if (rowStart >= rowEnd && colStart >= colEnd)
        return;

    int rowDivide = (rowStart + rowEnd) / 2;
    int colDivide = (colStart + colEnd) / 2;

    Divide(rowStart, rowDivide, colStart, colDivide);
    Divide(rowDivide + 1, rowEnd, colDivide + 1, colEnd);
    Divide(rowStart, rowDivide, colDivide + 1, colEnd);
    Divide(rowDivide + 1, rowEnd, colStart, colDivide);

    Merge(rowStart, rowEnd, colStart, colEnd);
}

int main()
{
    cin >> rows >> cols;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat[i][j];

    Divide(0, rows - 1, 0, cols - 1);

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cout << mat[i][j] << " ";
}
