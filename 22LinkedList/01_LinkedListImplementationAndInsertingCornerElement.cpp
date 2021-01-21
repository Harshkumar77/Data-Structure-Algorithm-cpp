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

void insertAtHead(int val , node*&head)
{
    node*n=new node(val);
    n->next=head;
    head=n;
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
int main()
{
    node *n=NULL;
    insertAtTail(1, n);
    insertAtTail(23, n);
    insertAtHead(69,n);
    printLinkedList(n);
    return 0;
}