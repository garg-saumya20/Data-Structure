#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
int getMaxWidth(Node *root)
{

    // Your code here
    if (root == NULL)
    {
        return 0;
    }
    queue<Node *> q;
    q.push(root);
    int ans = INT_MIN;
    int n;
    while (q.size() > 0)
    {

        n = q.size();
        ans = max(ans, n);
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    return ans;
}