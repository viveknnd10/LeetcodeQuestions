class Solution {
public:
    int maxPath=0;
    int diameter(TreeNode* root)
    {
      if(!root)
      {
        return 0;
      }
      if(!root->left && !root->right)
      {
        return 1;
      }
      int left,right,currlength,temp;
      left=diameter(root->left);
      right=diameter(root->right);
      currlength=max(left,right);
      maxPath=max(maxPath,max(currlength,left+right));
      return 1+currlength;
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
      diameter(root);
      return maxPath;
        
    }
};