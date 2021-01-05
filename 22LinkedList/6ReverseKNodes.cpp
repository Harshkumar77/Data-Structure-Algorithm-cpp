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

node* reverseK(node*&n,int k)
{
    node *prev = NULL ;node* curr = n ;
    node*nxt;
    int c=k;
    while(curr!=NULL and c--)
    {
        nxt = curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    if(nxt!=NULL) n->next=reverseK(nxt,k);
    return prev;
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
        cout << head->data << "->", head =
head->next;
    cout << "NULL\n";
}

int main()
{
    int size, s;
    cin >> size;
    node *n = NULL;
    int val;
    s = size;
    while (size--)
        cin >> val, insertAtTail(val, n);
    printLinkedList(n);
    n=reverseK(n,2);
    printLinkedList(n);
    return 0;
}