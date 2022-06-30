// Recursive Method

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
-333
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void solve(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    Node *curr == root;
    Node *predecessor;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            v.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                v.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

vector<int> morris(Node *root)
{
    vector<int> v;
    solve(root, v);
    return v;
}
