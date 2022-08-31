// slow and fast pointer approach

class Solution
{
public:
    // Function to check if the linked list has a loop.
    Node *FirstNodeInLoop(Node *head)
    {
        // your code here
        Node *slow = head;
        Node *fast = head;
        Node *first = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (slow != first)
                {
                    slow = slow->next;
                    first = first->next;
                }
            }
            break;
        }
        return slow;
    }
};