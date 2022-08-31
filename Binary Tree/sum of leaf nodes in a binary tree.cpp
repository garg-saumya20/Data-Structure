int sumLeaf(Node* root)
{
    // Code here
    if(root==NULL) 
    {
        return 0;
    }
    if(!root->left && !root->right)
    {
        return root->data;
    }
    int l=sumLeaf(root->left);
    int r=sumLeaf(root->right);
    return l+r;
}