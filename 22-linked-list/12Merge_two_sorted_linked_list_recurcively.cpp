// merge two sorted linked list recursively
node* merge(node*h1 , node*h2)
{
    if(h1==NULL) return h2;
    if(h2 ==NULL) return h1;
    node* res ;
    if(h1->data<h2->data)
    {
        res = h1;
        res->next = merge(h1->next , h2);
    }
    else
    {
        res = h2;
        res->next = merge(h2->next , h1);
    }
    return res;
}