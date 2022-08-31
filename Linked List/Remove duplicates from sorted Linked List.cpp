Node *removeDuplicates(Node *head)
{
 // your code goes here
 Node* curr=head;
 while(curr)
 {
     if(curr->next && curr->next->data==curr->data)
     {
         Node * next_next=curr->next->next;
         Node* node_to_delete=curr->next;
         delete(node_to_delete);
         curr->next=next_next;
     }
     else
     {
         curr=curr->next;
     }
 }
 return head;
}