// By Level Order Traversal

int getLevel(struct Node *node, int target)
{
    // code here
    if (node == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    int level = 1;
    q.push(node);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->data == target)
            {
                return level;
                break;
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        level++;
    }
    return 0;
}