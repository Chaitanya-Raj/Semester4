#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void countSort(int A[], int n)
{
    int B[10];
    int C[10];
    int k = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > k)
            k = A[i];
    }

    for (int i = 0; i <= k; ++i)
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        C[A[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        C[i] += C[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    for (int i = 0; i < n; i++)
        A[i] = B[i];
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    int A[n];
    cout << "Enter the elements of the array : " << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];

    countSort(A, n);

    cout << "The Sorted Array is : ";
    printArray(A, n);

    return 0;
}
