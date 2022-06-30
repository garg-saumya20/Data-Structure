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

// Solved Using Two Stacks

vector<int> findSpiral(Node *root)
{
    // Your code here
    vector<int> v;
    stack<Node *> s1;
    stack<Node *> s2;

    if (root == NULL)
    {
        return v;
    }
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            Node *temp = s1.top();
            s1.pop();
            v.push_back(temp->data);
            if (temp->right)
            {
                s2.push(temp->right);
            }
            if (temp->left)
            {
                s2.push(temp->left);
            }
        }

        while (!s2.empty())
        {
            Node *temp = s2.top();
            s2.pop();
            v.push_back(temp->data);
            if (temp->left)
            {
                s1.push(temp->left);
            }
            if (temp->right)
            {
                s1.push(temp->right);
            }
        }
    }
    return v;
}
