#include <iostream>
using namespace std;

void mergeSquareArrays(int **arr, int rst, int midRow, int rnd, int cst, int midCol, int cnd)
{
    // find sizes of arrays
    int c1 = midCol - cst + 1;
    int c2 = cnd - midCol;

    // sort horizontally
    for (int x = 0; x <= rnd - rst; x++)
    {
        // declare temp arrays for merging later
        int tempCL[c1], tempCR[c2];
        int i, j = 0;
        // copy elements
        for (i = 0; i < c1; i++)
        {
            tempCL[i] = arr[rst + x][cst + i];
        }
        // copy elements
        for (i = 0; i < c2; i++)
        {
            tempCR[i] = arr[rst + x][midCol + i + 1];
        }
        // select starting point
        int b = cst;
        i = 0;
        // perform actual merging based on comparison
        while (i < c1 && j < c2)
        {
            if (tempCL[i] <= tempCR[j])
            {
                arr[rst + x][b] = tempCL[i];
                i++;
            }
            else
            {
                arr[rst + x][b] = tempCR[j];
                j++;
            }
            b++;
        }
        // start copying leftover elements
        for (; i < c1; i++)
        {
            arr[rst + x][b] = tempCL[i];
            b++;
        }
        for (; j < c2; j++)
        {
            arr[rst + x][b] = tempCR[j];
            b++;
        }
    }

    // sort vertically
    int r1 = midRow - rst + 1;
    int r2 = rnd - midRow;

    for (int x = 0; x <= cnd - cst; x++)
    {
        // declare temp arrays for merging later
        int tempRL[r1], tempRR[r2];
        int i, j = 0;
        // copy elements
        for (i = 0; i < r1; i++)
        {
            tempRL[i] = arr[rst + i][cst + x];
        }
        // copy elements
        for (i = 0; i < r2; i++)
        {
            tempRR[i] = arr[midRow + i + 1][cst + x];
        }
        // select starting point
        int b = rst;
        i = 0;
        // perform actual merging based on comparison
        while (i < r1 && j < r2)
        {
            if (tempRL[i] <= tempRR[j])
            {
                arr[b][cst + x] = tempRL[i];
                i++;
            }
            else
            {
                arr[b][cst + x] = tempRR[j];
                j++;
            }
            b++;
        }
        // start copying leftover elements
        for (; i < r1; i++)
        {
            arr[b][cst + x] = tempRL[i];
            b++;
        }
        for (; j < r2; j++)
        {
            arr[b][cst + x] = tempRR[j];
            b++;
        }
    }
}

void mergeSort2d(int **arr, int rst, int rnd, int cst, int cnd)
{
    // after repetitive recurson if row end var decreases less than row start we need to stop
    if (rst >= rnd && cst >= cnd)
    {
        return;
    }
    // find the mid row and col at any instant
    int midRow = (rst + rnd) / 2;
    int midCol = (cst + cnd) / 2;

    // call merge sort on top left
    mergeSort2d(arr, rst, midRow, cst, midCol);
    // call merge sort on top right
    mergeSort2d(arr, rst, midRow, midCol + 1, cnd);
    // call merge sort on bottom left
    mergeSort2d(arr, midRow + 1, rnd, cst, midCol);
    // call merge sort on bottom right
    mergeSort2d(arr, midRow + 1, rnd, midCol + 1, cnd);
    // start merging arrays
    mergeSquareArrays(arr, rst, midRow, rnd, cst, midCol, cnd);
}

// function to print arrays
void printMulti(int **multi, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << multi[i][j] << " ";
        }
    }
}

int main()
{
    // declare size of matrix
    int row, col;
    cin >> row >> col;
    // using heap declare 2d array so array is shareable
    int **multi = new int *[row];

    for (int i = 0; i < row; i++)
        multi[i] = new int[col];

    // input array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> multi[i][j];
        }
    }

    // call merge sort
    mergeSort2d(multi, 0, row - 1, 0, col - 1);
    // preint the sorted array
    printMulti(multi, row, col);

    return 0;
}
