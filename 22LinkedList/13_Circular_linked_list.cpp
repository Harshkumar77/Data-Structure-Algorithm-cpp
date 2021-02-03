#include <iostream>
using namespace std;

class node
{
public:
    node *next = NULL;
    int data;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        n->next = n;
        head = n;
    }
    n->next = head;
    node *temp = head->next;
    for (; temp->next != head; temp = temp->next)
        ;
    temp->next = n;
    head = n;
}
void insertAtTail(node *&head, int val)
{
    node*n=new node(val);
    if(head==NULL)
    {
        n->next = n;
        head = n;    
        return;
    }   
    node*temp=head->next;
    for(;temp->next!=head;temp=temp->next);
    temp->next=n;
    n->next=head;
}
int size(node*head)
{
    int i =0;
    if(head==NULL)
        return i;
    ++i;
    for(node*temp=head->next;temp!=head;temp=temp->next)
        ++i;
    return i;
}
void deleteAt(node*&head , int index)
{
    // linked list is zero based index
    if(head==NULL or index<0 or index>=size(head))
        return;
    if(head->next==head)
    {
        head=NULL;
        return;
    }else if(index==0)
    {
        head->data=head->next->data;
        head->next=head->next->next;
        return;
    }
    node*prev=head;
    for(int i=0;i!=index-1;++i,prev=prev->next);
    prev->next=prev->next->next;
}
void display(node *&head)
{
    if (head == NULL)
    {
        cout << "EMPTY\n";
        return;
    }
    cout << head->data << " ";
    for (node *temp = head->next; temp != head; cout << temp->data << " ", temp = temp->next)
        ;
    cout << '\n';
}
int main()
{

    node *n = NULL;
    // display(n);
    insertAtTail(n, 1123);
    // display(n);
    insertAtTail(n, 121);
    // display(n);
    insertAtTail(n, 13);
    // display(n);
    insertAtTail(n, 11);
    // display(n);
    insertAtTail(n, 14);
    // display(n);
    insertAtTail(n, 4);
    display(n);
    deleteAt(n,5);
    display(n); 
    return 0;
}