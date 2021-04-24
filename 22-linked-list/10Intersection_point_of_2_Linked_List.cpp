//function returning the value of instersection node in a linked list 
int intersectingValue(node*head1 , int l1 , node*head2 , int l2)
{
    node *p1 = head1,*p2 = head2;
    if(l1>l2) 
    {
        for(int i=0 ; i<l1-l2;i++) p1=p1->next; 
    }
    else 
        for(int i=0 ; i<l2-l1;i++) p2=p2->next; 
    for(;p1!=NULL and p2!=NULL and p1!=p2;p1=p1->next , p2=p2->next);
    if(p1==p2) return p1->data;
    else return -1;    
}