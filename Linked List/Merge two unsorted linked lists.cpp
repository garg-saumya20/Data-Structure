Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here
    Node* l1=head1;
    Node* l2=head2;
    Node* result=NULL;
    Node* temp=NULL;
    if(l1==NULL)
    {
        return l2;
    }
    if(l2==NULL)
    {
        return l1;
    }
    if(l1->data>l2->data)
    {
        swap(l1,l2);
    }
    result=l1;
    while(l1 && l2)
    {
        while(l1 && l1->data<=l2->data)
        {
             temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return result;
}  