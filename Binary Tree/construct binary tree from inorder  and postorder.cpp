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
Node *solve(int in[], int post[], int &index, int start, int end, int n, map<int, int> &m)
{
    if (index < 0 || start > end)
    {
        return NULL;
    }
    int element = post[index--];
    Node *root = new Node(element);
    int pos = m[element];
    root->right = solve(in, post, index, pos + 1, end, n, m);
    root->left = solve(in, post, index, start, pos - 1, n, m);
    return root;
}
Node *buildTree(int in[], int post[], int n)
{
   
    int postOrderIndex = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[in[i]] = i;
    }
    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, m);
    return ans;
}