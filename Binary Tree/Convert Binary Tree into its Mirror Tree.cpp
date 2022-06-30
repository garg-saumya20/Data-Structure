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
void mirror(Node* node) {
        // code here
        if(node==NULL)
        {
            return;
        }
        mirror(node->left);
        mirror(node->right);
        struct Node* temp;
        temp=node->left;
        node->left=node->right;
        node->right=temp;
    }