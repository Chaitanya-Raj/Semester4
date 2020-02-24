#include <iostream>
#include "sll.cpp"
using namespace std;

void DFSUtil(LinkedList<int> l[], int n, int s, LinkedList<int> x[], bool discovered[])
{
    discovered[s] = true;
    Node<int> *temp = l[s].head;
    while (temp != NULL)
    {
        if (!discovered[temp->data])
        {
            x[s].insertionTail(temp->data);
            DFSUtil(l, n, temp->data, x, discovered);
        }
        temp = temp->next;
    }
}

void DFS(LinkedList<int> l[], int n, int s)
{
    LinkedList<int> x[n];
    for (int i = 0; i < n; i++)
    {
        x[i].insertionTail(i);
    }
    bool *discovered = new bool[n];
    for (int i = 0; i < n; i++)
        discovered[i] = false;

    DFSUtil(l, n, s, x, discovered);
    for (int i = 0; i < n; i++)
    {
        x[i].display();
        cout << endl;
    }
}

int main()
{
    cout << "\nChoose one of the following : \n";
    cout << "1.Undirected\n";
    cout << "2.Directed\n";
    int choice;
    cin >> choice;
    cout << "\nEnter number of vertices : ";
    int n;
    cin >> n;
    LinkedList<int> l[n], x[n];
    for (int i = 0; i < n; i++)
    {
        l[i].insertionTail(i);
    }
    cout << "\nEnter the edges(0 to " << n - 1 << ") : ";
    while (true)
    {
        int x, y;
        cout << "\nFrom : ";
        cin >> x;
        cout << "\nTo : ";
        cin >> y;
        if (x == -1 || y == -1)
            break;
        l[x].insertionTail(y);
        if (choice == 1)
            l[y].insertionTail(x);
    };
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        l[i].display();
    }
    int s;
    while (true)
    {
        cout << "\n\nChoose source vertex : ";
        cin >> s;
        if (s == -1)
            break;
        cout << "\n\n";
        DFS(l, n, s);
        cout << endl;
    }
    return 0;
}
