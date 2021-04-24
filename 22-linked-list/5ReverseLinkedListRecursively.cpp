#include <bits/stdc++.h>

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

node *reverseLinkedList(node *&head)
{
    if(head==NULL or head->next==NULL) return head;
    node *p = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size, s;
    cin >> size;
    node *n = NULL;
    int val;
    s = size;
    node *t = n;
    while (size--)
        cin >> val, insertAtTail(val, n);
    printLinkedList(n);
    n = reverseLinkedList(n);
    printLinkedList(n);
    return 0;
}