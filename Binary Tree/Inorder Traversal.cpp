// Recursive Method

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
void solve(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}

vector<int> inorder(Node *root)
{

    vector<int> v;
    solve(root, v);
    return v;
}
