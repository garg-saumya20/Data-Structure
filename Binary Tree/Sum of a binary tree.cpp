long int sumBT(Node* root)
{
    // Code here
    if(root==NULL)
    {
        return 0;
    }
   
    int l =sumBT(root->left);
    int r=sumBT(root->right);
    return root->key+l+r;
}