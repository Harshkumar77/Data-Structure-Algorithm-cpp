#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(int val, node *&head)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = n;
}

void insertAtHead(int val, node *&head)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void printLinkedList(node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

int searchInLinkedList(int key, node *&head)
{
    int pos = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return pos;
        pos++;
        temp = temp->next;
    }
    return -1;
}

int main()
{
    node *n = NULL;
    int val, key;
    cin >> key;
    while (cin >> val)
        insertAtTail(val, n);
    printLinkedList(n);
    cout<<'\n'<<searchInLinkedList(key,n);
    return 0;
}