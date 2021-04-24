// Program to merge two sorted linked list iteratively
node* merge(node*h1 , node*h2)
{
    node* dummy = new node(-1);
    node* ans = dummy ;
    for(;h1!=NULL and h2!=NULL ;dummy=dummy->next)
    {
        if(h1->data < h2->data)
        {
            dummy->next=h1;
            h1=h1->next;
        }
        else
        {
            dummy->next=h2;
            h2=h2->next;
        }
        
    }
    for(;h1!=NULL;h1=h1->next , dummy=dummy->next)
    {
        dummy->next=h1;
    }
    for(;h2!=NULL;h2=h2->next , dummy=dummy->next)
    {
        dummy->next=h2;
    }
    return ans->next;
}