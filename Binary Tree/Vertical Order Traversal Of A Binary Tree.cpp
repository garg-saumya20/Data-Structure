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

vector<int> verticalOrder(Node *root)
    {
        //Your code here
         vector<int> v;
    if (root == NULL)
    {
        return v;
    }

    queue<pair<Node *, int>> q;
    //Agar yaha pe unordered_map loge,to answer match nii hoga.

    map<int, vector<int>> m;
    q.push({root, 0});
    int mn=0,mx=0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *temp = it.first;
        int line = it.second;
        
            m[line].push_back(temp->data);
        
        if (temp->left)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right)    
        {
            q.push({temp->right, line + 1});
        }
        if(mn>line)
          mn=line;
        else if(mx<line)
          mx=line;
    }
    for (int i=mn;i<=mx;i++)
    {
        vector<int> tmp=m[i];
        for(int j=0;j<tmp.size();j++)
        v.push_back(tmp[j]);
      }
    return v;
    }