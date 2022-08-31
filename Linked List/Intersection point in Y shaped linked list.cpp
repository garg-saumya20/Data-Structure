int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
     Node* a=head1;
        Node* b=head2;
        if(a==NULL || b==NULL)
        {
            return NULL;
        }
        while(a!=b)
        {
            a=a?a->next:head2;
            b=b?b->next:head1;
        }
        return a->data;
}
