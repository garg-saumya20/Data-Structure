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

vector<int> topView(Node *root)
{
    // Your code here
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }

    queue<pair<Node *, int>> q;
    //Agar yaha pe unordered_map loge,to answer match nii hoga.

    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *temp = it.first;
        int line = it.second;
        if (m.find(line) == m.end())
        {
            m[line] = temp->data;
        }
        if (temp->left)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right)    
        {
            q.push({temp->right, line + 1});
        }
    }
    for (auto it : m)
    {
        v.push_back(it.second);
    }
    return v;
}
