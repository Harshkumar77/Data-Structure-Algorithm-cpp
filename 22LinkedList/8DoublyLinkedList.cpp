#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }
    node *n = new node(val);
    n->next = head;
    head->prev = n;
    head = n;
}
void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *temp = head;
    for (temp; temp->next != NULL; temp = temp->next)
        ;
    node *n = new node(val);
    n->prev = temp;
    temp->next = n;
}
void deleteAt(node *&head, int idx)
{
    if (idx == 0)
        return;
    if (idx == 1)
    {
        head->next->prev = NULL;
        head = head->next;
        delete head->prev;
        return;
    }
    int count = 1;
    node *temp = head;
    for (; temp->next != NULL and count != idx; temp = temp->next, count++)
        ;
    if (count == idx and temp->next == NULL)
    {
        temp->prev->next = NULL;
        delete temp;
        return;
    }
    if (temp->next == NULL)
        return;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
void display(node *head)
{
    cout << "NULL<->";
    for (node *n = head; n != NULL; n = n->next)
        cout << n->data << "<->";
    cout << "NULL\n";
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    deleteAt(head, 1);
    display(head);
}