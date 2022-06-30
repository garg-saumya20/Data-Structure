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

Node *solve(int in[], int pre[], int &index, int start, int end, int n, map<int, int> &m)
{
    if (index >= n || start > end)
    {
        return NULL;
    }
    int element = pre[index++];
    Node *root = new Node(element);
    int pos = m[element];
    root->left = solve(in, pre, index, start, pos - 1, n, m);
    root->right = solve(in, pre, index, pos + 1, end, n, m);
    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    int preOrderIndex = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[in[i]] = i;
    }
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, m);
    return ans;
}