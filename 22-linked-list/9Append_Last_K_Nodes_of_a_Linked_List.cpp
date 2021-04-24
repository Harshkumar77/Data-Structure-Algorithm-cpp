node *appendK(node *head, int k)
{
    int l = length(head);
    if (k == 0 or head->next == NULL or head == NULL or k > l - 1)
        return head;
    node *tail = head, *newTail, *newHead;
    for (int count = 0; tail->next != NULL; tail = tail->next, count++)
    {
        if (count == l - k)
            newHead = tail;
        if (count == l - k - 1)
            newTail = tail;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}