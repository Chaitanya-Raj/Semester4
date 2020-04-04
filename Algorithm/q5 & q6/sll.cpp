#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    LinkedList()
    {
        head = NULL;
    }
    // void insertionHead(T n)
    // {
    //     Node<T> *temp = new Node<T>;
    //     temp->data = n;
    //     temp->next = head;
    //     head = temp;
    // }
    void insertionTail(T n)
    {
        Node<T> *temp = new Node<T>;
        temp->data = n;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node<T> *p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
            ;
        }
    }
    int deletionHead()
    {
        if (head != NULL)
        {
            Node<T> *delnode = head;
            //cout << "element deleted " << head->data;
            head = head->next;
            int temp = delnode->data;
            delnode->next = NULL;
            delete delnode;
            return temp;
        }
        else
        {
            //cout << "List empty";
        }
    }
    // void deletionTail()
    // {
    //     if (head != NULL)
    //     {
    //         if (head->next == NULL)
    //         {
    //             Node<T> *delnode = head;
    //             //cout << "element deleted " << head->data;
    //             head = NULL;
    //             delete delnode;
    //         }
    //         else
    //         {
    //             Node<T> *temp = head;
    //             while (temp->next->next != NULL)
    //                 temp = temp->next;
    //             //cout << "element deleted " << temp->next->data;
    //             Node<T> *delnode = temp->next;
    //             delete delnode;
    //             temp->next = NULL;
    //         }
    //     }
    //     else
    //     {
    //         //cout << "List empty";
    //     }
    // }
    void display()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "!!!";
    }
};
