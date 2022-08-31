int getSize(Node* node)
{
   // Your code here
   if(node==NULL)
   {
       return 0;
   }
  int left_subtree=getSize(node->left);
  int right_subtree=getSize(node->right);
  int ans=left_subtree+right_subtree;
  return ans+1;
}