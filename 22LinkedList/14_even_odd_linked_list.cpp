void evenOdd(node *&head)
{
    if (head == NULL or head->next == NULL)
        return;
    node *odd = head, *even = head->next, *evenHead = head->next;
    while(odd->next!=NULL and even->next!=NULL)
    {
        if(odd->next->next!=NULL)
            odd ->next=odd->next->next , odd=odd->next;
        if(even->next->next!=NULL)
            even ->next=even->next->next , even=even->next;
    }
    odd->next=evenHead;
    if(even->next!=NULL)
        even->next=NULL;
}