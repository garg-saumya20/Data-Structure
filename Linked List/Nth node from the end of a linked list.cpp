//variation of remove nth node from the end of a Linked List


int getNthFromLast(Node *head, int n)
{
       // Your code here
       
       Node* dummyNode=new Node(0);
       dummyNode->next=head;
       Node* slow=dummyNode;
       Node* fast=dummyNode;
       
       
       for(int i=1;i<=n;i++)
       {
           fast=fast->next;
           if(fast==NULL)
       {
           return -1;
           break;
       }
       }
       
       while( fast && fast->next)
       {
           slow=slow->next;
           fast=fast->next;
       }
       return slow->next->data;
}