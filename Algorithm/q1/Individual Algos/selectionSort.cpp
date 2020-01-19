#include <iostream>
#include <cstdlib>
using namespace std;

int count = 0;

void selectionSort(int arr[], int size)
{
    count = 0;
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            count++;
            if (arr[j] < arr[min])
            {
                min = j;
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main()
{
    int size = 30;
    int arr[size];
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;

    cout << "\n\nBest Case\n";
    cout << "\n\nBefore sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];

    selectionSort(arr, size);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];

    cout << "\n\nNumber of comparisons : " << count << endl;

    count = 0;

    int ar[30];
    int x = 30;
    for (int i = 0; i < size; i++)
        ar[i] = x--;

    cout << "\n\nWorst Case\n";
    cout << "\n\nBefore sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << ar[i];

    selectionSort(ar, size);

    cout << "\n\nAfter sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << ar[i];

    cout << "\n\nNumber of comparisons : " << count << endl;

    cout << "\n\nRandom Cases\n";

    for (int j = 0; j < 8; j++)
    {
        count = 0;
        int x = 30;
        int a[x];
        for (int i = 0; i < x; i++)
        {
            a[i] = (rand() % 100) + 20;
        }
        cout << "\n\nBefore sort\n";
        for (int i = 0; i < size; i++)
            cout << "\t" << a[i];

        selectionSort(a, size);

        cout << "\n\nAfter sort\n";
        for (int i = 0; i < size; i++)
            cout << "\t" << a[i];

        cout << "\n\nNumber of comparisons : " << count << endl;
    }

    return 0;
}