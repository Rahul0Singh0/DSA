#include <iostream>
#include <vector>

using namespace std;

// Lecture based
void InsertA(int A[], int n)
{
    int i = n;
    int temp = A[n];
    while (i > 0 && temp > A[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        A[i] = A[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertA(A, i);
    }
}
int Delete(int A[], int n)
{
    int i, j, x, temp, val;
    val = A[0];
    x = A[n];
    A[0] = A[n];
    A[n] = val;
    i = 0;
    j = i * 2 + 1;
    while (j <= n - 1)
    {
        if (j < n - 1 && A[j + 1] > A[j])
            j = j + 1;
        if (A[i] < A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = 2 * j + 1;
        }
        else
            break;
    }
    return val;
}

template <class T>
void Print(T &vec, int n)
{
    cout << "Max Heap: [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
        {
            cout << ", " << flush;
        }
    }
    cout << "]" << endl;
}

int main()
{

    // int a[] = {45, 35, 15, 30, 10, 12, 6, 5, 20, 50};
    int a[] ={40,35,30,15,10,25,5};
    createHeap(a, 10);
    Print(a, sizeof(a) / sizeof(a[0]));
    cout << endl;
    // cout<<Delete(a, 9)<<endl;
    // Print(a, sizeof(a) / sizeof(a[0]));
    return 0;
}