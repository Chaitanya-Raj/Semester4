#include <iostream>
using namespace std;

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

int getMax(int A[], int n)
{
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}

void countSort(int A[], int n, int exp)
{
    int B[n];
    int i, C[10] = {0};

    for (i = 0; i < n; i++)
        C[(A[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        C[i] += C[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        B[C[(A[i] / exp) % 10] - 1] = A[i];
        C[(A[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        A[i] = B[i];
}

void radixsort(int A[], int n)
{
    int d = getMax(A, n);

    for (int exp = 1; d / exp > 0; exp *= 10)
        countSort(A, n, exp);
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

    radixsort(A, n);

    cout << "The Sorted Array is : ";
    printArray(A, n);

    return 0;
}
