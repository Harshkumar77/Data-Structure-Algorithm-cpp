bool detectLoop(node *head)
{
    node *slow = head->next, *fast = head->next->next;
    while (fast->next != NULL and fast != NULL)
    {
        if (fast == slow)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

void deleteLoop(node *&n)
{
    if (!detectLoop(n))
        return;
    node *slow = n, *fast = n;
    slow = slow->next;
    fast = fast->next->next;
    while (fast->next != NULL and fast != NULL)
    {
        if (fast == slow)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = n;
    while (fast->next == slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}