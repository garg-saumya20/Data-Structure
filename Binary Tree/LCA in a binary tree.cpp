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
Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL)
       {
           return NULL;
       }
       if(root->data==n1 || root->data==n2)
       {
           return root;
       }
       Node* l=lca(root->left,n1,n2);
       Node* r=lca(root->right,n1,n2);
       if(l && r)
       {
           return root;
       }
       else if(l && !r)
       {
           return l;
       }
       else if(!l && r)
       {
           return r;
       }
       else 
       return NULL;
    }