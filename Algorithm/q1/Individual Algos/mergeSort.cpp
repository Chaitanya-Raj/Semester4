#include <iostream>
#include <cstdlib>
using namespace std;
int count = 0;

void merge(int a[], int low, int high, int mid)
{
    int i, j, k, temp[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            count++;
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            count++;
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        count++;
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        count++;
        temp[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i - low];
    }
}
void mergesort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, high, mid);
    }
}

int main()
{
    int size = 30;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }

    cout << "\n\nBest Case\n";
    cout << "\n\nBefore sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];

    mergesort(arr, 0, size - 1);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];

    cout << "\n\nNumber of comparisons : " << count << endl;

    int x = 30;
    count = 0;
    for (int i = 0; i < size; i++)
        arr[i] = x--;

    cout << "\n\nWorst Case\n";
    cout << "\n\nBefore sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];

    mergesort(arr, 0, size - 1);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];

    cout << "\n\nNumber of comparisons : " << count << endl;

    cout << "\n\nRandom Cases\n";

    for (int j = 0; j < 8; j++)
    {
        count = 0;
        for (int i = 0; i < size; i++)
        {
            arr[i] = (rand() % 100) + 20;
        }
        cout << "\n\nBefore sort\n";
        for (int i = 0; i < size; i++)
            cout << "\t" << arr[i];

        mergesort(arr, 0, size - 1);

        cout << "\n\nAfter sort\n";
        for (int i = 0; i < size; i++)
            cout << "\t" << arr[i];

        cout << "\n\nNumber of comparisons : " << count << endl;
    }
}