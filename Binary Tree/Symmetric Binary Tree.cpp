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
bool solve(Node *r1, Node *r2)
{
    if (!r1 && !r2)
    {
        return true;
    }
    else if (r1 && !r2)
    {
        return false;
    }
    else if (!r1 && r2)
    {
        return false;
    }
    else
    {
        if (r1->data == r2->data && solve(r1->left, r2->right) && solve(r1->right, r2->left))
            return true;

        else
            return false;
    }
}
bool isSymmetric(struct Node *root)
{
    // Code here
    if (root == NULL)
    {
        return 0;
    }
    return solve(root->left, root->right);
}