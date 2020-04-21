#include <iostream>
using namespace std;

class SubSet
{
    int **arr;
    int *set;
    int n;
    int w;

public:
    SubSet(int count, int sum)
    {
        n = count;
        w = sum;
        arr = new int *[n + 1];
        for (int i = 0; i <= n; i++)
            arr[i] = new int[w + 1];
        set = new int[n + 1];
    }

    void input()
    {
        cout << "Enter the positive Set...\n";
        for (int i = 1; i <= n; i++)
            cin >> set[i];
    }

    bool subset_sum()
    {
        for (int i = 0; i <= w; i++)
            arr[0][i] = 0;

        for (int i = 0; i <= n; i++)
            arr[i][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (j < set[i])
                    arr[i][j] = arr[i - 1][j];
                else
                    arr[i][j] = max(arr[i - 1][j], set[i] + (arr[i - 1][j - set[i]]));
            }
        }

        for (int i = n; i >= 0; i--)
        {
            for (int j = 0; j <= w; j++)
                cout << arr[i][j] << "   ";

            cout << endl;
        }

        if (arr[n][w] == w)
            return true;
        else
            return false;
    }

    void backtrack(int i, int W)
    {
        if (i == 0 || W == 0)
            return;
        else
        {
            if (set[i] > W || arr[i][W] == arr[i - 1][W])
                backtrack(i - 1, W);
            else
            {
                cout << i << "\t";
                backtrack(i - 1, W - set[i]);
            }
        }
    }

    void print()
    {
        cout << "Elements Included : ";
        backtrack(n, w);
        cout << endl;
    }
};

int main()
{
    int count, sum;
    cout << "Enter the count of Numbers in a Set : ";
    cin >> count;
    cout << "Enter the Sum Expected : ";
    cin >> sum;

    SubSet *obj = new SubSet(count, sum);
    obj->input();

    if (obj->subset_sum())
        cout << "Yes, A subset can be Created...\n";
    else
        cout << "No, A subset can't be Created...\n";

    obj->print();
    return 0;
}
