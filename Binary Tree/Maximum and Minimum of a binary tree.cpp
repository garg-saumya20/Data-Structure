int findMax(Node *root)
{
    // code here
    if (root == NULL)
    {
        return INT_MIN;
    }
    int l = findMax(root->left);
    int r = findMax(root->right);
    int ans = max(max(l, r), root->data);
    return ans;
}
int findMin(Node *root)
{
    // code here
    if (root == NULL)
    {
        return INT_MAX;
    }
    int l = findMin(root->left);
    int r = findMin(root->right);
    int ans = min(min(l, r), root->data);
    return ans;
}