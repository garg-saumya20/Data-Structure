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

int solve(Node *root, int &res)
{
    if (root == NULL)
    {
        return 0;
    }
    int l = solve(root->left, res);
    int r = solve(root->right, res);
    int temp = max(l, r) + 1;
    int ans = max(temp, l + r + 1);
    res = max(ans, res);
    return temp;
}


int diameter(Node *root)
{
    int res = INT_MIN;
    solve(root, res);

    return res;
}
