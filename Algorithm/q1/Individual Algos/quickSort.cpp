#include <iostream>
#include <cstdlib>
using namespace std;
int count = 0;

int extendLargeRegion(int E[], int pivot, int lowVac, int high)
{
    int highVac, curr;
    highVac = lowVac;
    curr = high;
    while (curr > lowVac)
    {
        if (E[curr] < pivot)
        {
            E[lowVac] = E[curr];
            highVac = curr;
            count++;
            break;
        }
        curr--;
    }
    return highVac;
}

int extendSmallRegion(int E[], int pivot, int low, int highVac)
{
    int lowVac, curr;
    lowVac = highVac;
    curr = low;
    while (curr < highVac)
    {
        if (E[curr] >= pivot)
        {
            E[highVac] = E[curr];
            lowVac = curr;
            count++;
            break;
        }
        curr++;
    }
    return lowVac;
}

int partition(int E[], int pivot, int first, int last)
{
    int low, high;
    low = first;
    high = last;
    while (low < high)
    {
        int highVac = extendLargeRegion(E, pivot, low, high);
        int lowVac = extendSmallRegion(E, pivot, low + 1, highVac);
        low = lowVac;
        high = highVac - 1;
    }
    return low;
}

void QS(int E[], int first, int last)
{
    int pivot;
    if (first < last)
    {
        pivot = E[first];
        int splitpt = partition(E, pivot, first, last);
        E[splitpt] = pivot;
        QS(E, first, splitpt - 1);
        QS(E, splitpt + 1, last);
    }
}

int main()
{
    int size = 30;
    int arr[size];

    arr[0] = 15;
    for (int i = 1; i < size; i++)
    {
        if (i >= 15)
            arr[i] = i + 1;
        else if (i < 15)
            arr[i] = i;
    }

    cout << "\n\nBest Case\n";
    cout << "\n\nBefore sort\n";
    for (int i = 0; i < size; i++)
        cout << "\t" << arr[i];

    QS(arr, 0, size - 1);

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

    QS(arr, 0, size - 1);

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

        QS(arr, 0, size - 1);

        cout << "\n\nAfter sort\n";
        for (int i = 0; i < size; i++)
            cout << "\t" << arr[i];

        cout << "\n\nNumber of comparisons : " << count << endl;
    }
}