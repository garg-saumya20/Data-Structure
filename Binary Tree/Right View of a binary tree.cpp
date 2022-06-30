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

void solve(Node *root, int level, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    if (level == v.size())
    {
        v.push_back(root->data);
    }
    solve(root->right, level + 1, v);
    solve(root->left, level + 1, v);
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> v;
    solve(root, 0, v);
    return v;
}
