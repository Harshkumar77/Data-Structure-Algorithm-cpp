void insertBottom(stack<int> &s, int el)
{
    if (s.empty())
    {
        s.push(el);
        return;
    }
    int top =  s.top();
    s.pop();
    insertBottom(s,el);
    s.push(top);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
        return;
    int tp = s.top();
    s.pop();
    reverseStack(s);
    insertBottom(s, tp);
}