#include <iostream>
#include "sll.cpp"
using namespace std;

void DFSUtil(LinkedList<int> l[], int n, int v, bool visited[])
{
    visited[v] = true;
    cout << v << " ";

    Node<int> *temp = l[v].head;
    while (temp != NULL)
    {
        if (!visited[temp->data])
        {
            DFSUtil(l, n, temp->data, visited);
        }
        temp = temp->next;
    }
}

void DFS(LinkedList<int> l[], int n, int v)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    DFSUtil(l, n, v, visited);
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
    LinkedList<int> l[n];
    for (int i = 0; i < n; i++)
        l[i].insertionTail(i);
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
    cout << "\n\nChoose source vertex : ";
    int s;
    cin >> s;
    cout << "\n\n";
    DFS(l, n, s);
    cout << endl;
    return 0;
}
