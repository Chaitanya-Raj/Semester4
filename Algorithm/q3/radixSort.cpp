// C++ implementation of Radix Sort
#include <iostream>
using namespace std;

// A utility function to print an array
void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

// A utility function to get maximum value in arr[]
int getMax(int A[], int n)
{
    int mx = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > mx)
            mx = A[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int A[], int n, int exp)
{
    int B[n]; // output array
    int i, C[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        C[(A[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        C[i] += C[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        B[C[(A[i] / exp) % 10] - 1] = A[i];
        C[(A[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        A[i] = B[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int A[], int n)
{
    // Find the maximum number to know number of digits
    int d = getMax(A, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; d / exp > 0; exp *= 10)
        countSort(A, n, exp);
}

// Driver program to test above functions
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
