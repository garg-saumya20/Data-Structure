class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        
        //find middle of a linked list
        Node* slow=head;
        Node* fast=head;
        while(fast && fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        
        //reverse half of a linked list
        slow->next=reverse(slow->next);
        slow=slow->next;
        
        
        //Now,checking palindrome in linked list
        while(slow!=NULL)
        {
            if(head->data!=slow->data)
            {
                return false;
            }
            slow=slow->next;
            head=head->next;
        }
        return true;
        
    }
};
