#include <iostream>
#include "sll.cpp"
#include "queue.cpp"
using namespace std;

int main()
{
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
        l[y].insertionTail(x);
    };
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        l[i].display();
    }

    bool discovered[n];
    Queue<int> q(100);
    q.enqueue(0);
    discovered[0] = true;
    cout << "\n BFS is \n";
    while (q.front != -1)
    {
        int x = q.dequeue();
        cout << "\t" << x;
        Node<int> *temp = l[x].head;
        while (temp != NULL)
        {
            if (discovered[temp->data])
            {
                q.enqueue(temp->data);
                discovered[temp->data] = true;
            }
            temp = temp->next;
        }
    }
    cout << endl;
    return 0;
}