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

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(int val, node *&n)
{
    node *temp = n, *add = new node(val);
    if (n == NULL)
        n = add;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = add;
    }
}

void printLinkedList(node *head)
{
    while (head != NULL)
        cout << head->data << "->", head = head->next;
    cout << "NULL\n";
}

void deletion(node *&n, int val)
{
    if (n == NULL)
        return;
    if (n->data == val)
    {
        node *d = n;
        n = n->next;
        delete d;
        return;
    }
    node *temp = n;
    while (temp->next->data != val and temp != NULL)
        temp = temp->next;
    if (temp->next->data != val)
        return;
    node *d = temp->next;
    temp->next = temp->next->next;
    delete d;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, e;
    cin >> size >> e;
    node *n = NULL;
    int val;
    while (size--)
        cin >> val, insertAtTail(val, n);
    printLinkedList(n);
    deletion(n, e);
    printLinkedList(n);
    return 0;
}