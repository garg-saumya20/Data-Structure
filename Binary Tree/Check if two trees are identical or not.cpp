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
bool isIdentical(Node *r1, Node *r2)
{
    // Your Code here
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
        if (r1->data == r2->data && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right))
            return true;

        else
            return false;
    }
}