// Heap sort is a complete binary search
// node index i
// left child is 2*i
// right child is 2*i + 1
// height is log2(n)
// duplicates are allowed
#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void InsertMaxHeap(int A[], int n)
{
    int temp, i = n;
    temp = A[n];
    while (i > 1 && temp > A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

void DeleteHeapHead(int A[], int n)
{
    int x, i, j, val;
    // store to be deleted value
    val = A[1];
    // change head with last element
    A[1] = A[n];
    i = 1;
    // take a j variable based on position of i
    j = 2 * i;
    // while loop is one less than switched element
    while (j < n - 1)
    {
        // check which child is bigger left or right
        if (A[j + 1] > A[j])
            j = j + 1;
        // depending on bigger elemnt change
        if (A[i] < A[j])
        {
            swap(A[i], A[j]);
            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    A[n] = val;
}

/*
void InsertMinHeap(int A[], int n)
{
    int temp, i = n;
    temp = A[n];
    while (i > 1 && temp < A[i / 2])
    {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}
 */

int main()
{
    int noe; // 7
    cout << "Enter number of elements" << endl;
    cin >> noe;
    noe += 1;
    // declare a array with number of elements + 1
    int heaper[noe] = {0}; // 8
    int i;
    for (i = 1; i < noe; i++) // 7
    {
        cin >> heaper[i];
    }
    // Insert in heap using function from third element onwards
    for (i = 2; i < noe; i++)
    {
        InsertMaxHeap(heaper, i);
    }

    // delete heads of head and update them at end
    for (i = noe - 1; i > 1; i--)
    {
        DeleteHeapHead(heaper, i);
    }

    for (int i = 1; i < sizeof(heaper) / sizeof(heaper[0]); i++)
    {
        cout << heaper[i] << " ";
    }
    return 0;
}