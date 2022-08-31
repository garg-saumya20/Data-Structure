//deete a node at a given position
//Variation of Nth node from end of a linked list


Node* deleteNode(Node *head,int x)
{
    //Your code here
   Node* dummyNode=new Node(0);
   dummyNode->next=head;
   Node* slow=dummyNode;
   Node* fast=dummyNode;
   
   if(x ==1)
   {
       return head->next;
   }
   fast=fast->next;
   for(int i=1;i<=x-1;i++)
   {
      fast=fast->next;
      slow=slow->next;
   }
    slow->next=fast->next;
    return head;
    
}