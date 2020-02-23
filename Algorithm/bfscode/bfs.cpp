#include <iostream>
#include "sll.cpp"
using namespace std;

void bfs(LinkedList<int> l[], int n, int s)
{
    bool *discovered = new bool[n];
    for (int i = 0; i < n; i++)
        discovered[i] = false;

    LinkedList<int> q, x[n];
    for (int i = 0; i < n; i++)
        x[i].insertionTail(i);
    discovered[s] = true;
    q.insertionTail(s);

    while (q.head)
    {
        s = q.deletionHead();
        Node<int> *temp = l[s].head;
        while (temp != NULL)
        {
            if (!discovered[temp->data])
            {
                x[s].insertionTail(temp->data);
                discovered[temp->data] = true;
                q.insertionTail(temp->data);
            }
            temp = temp->next;
        }
    }
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
    }
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        l[i].display();
    }
    cout << "\n\nChoose source vertex : ";
    int s;
    cin >> s;
    cout << "\n\n";
    bfs(l, n, s);
    cout << endl;
    return 0;
}