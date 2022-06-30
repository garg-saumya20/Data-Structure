class Solution {
public:
void leftBoundary(Node* root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    if(root->left || root->right)
    {
        v.push_back(root->data);
    }
    if(root->left)
    leftBoundary(root->left,v);
    if(root->right)
    leftBoundary(root->right,v);
}
void rightBoundary(Node* root,vector<int> &tmp)
{
    if(root==NULL)
    {
        return;
    }
    
  if(root->left || root->right)
    {
        tmp.push_back(root->data);
    }
    if(root->right)
     rightBoundary(root->right,tmp);
     if(root->left)
    rightBoundary(root->left,tmp);
   
}
void leavesBoundary(Node* root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    if(!root->left && !root->right)
    {
        v.push_back(root->data);
    }
    if(root->left)
    {
        leavesBoundary(root->left,v);
    }
    if(root->right)
    {
        leavesBoundary(root->right,v);
    }
}
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> v;
           vector<int> tmp;
        if(root==NULL)
        {
            return v;
        }
        v.push_back(root->data);
        leftBoundary(root->left,v);
         leavesBoundary(root->left,v);
        leavesBoundary(root->right,v);
        rightBoundary(root->right,tmp);
        for (int i = tmp.size() - 1; i >= 0; --i) {
         v.push_back(tmp[i]);
  }
       
        return v;
    }
};