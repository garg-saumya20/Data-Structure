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


 vector<int> levelOrder(Node* node)
    {
      //Your code here
      vector<int> v;
      if(node==NULL)
      {
          return v;
      }
      queue<Node*>q;
      q.push(node);
      while(!q.empty())
      {
          Node* temp=q.front();
          q.pop();
          v.push_back(temp->data);
          if(temp->left)
          {
              q.push(temp->left);
          }
          if(temp->right)
          {
              q.push(temp->right);
          }
      }
      return v;
    }