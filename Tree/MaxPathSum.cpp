class Solution {
public:
  struct pathData
  {
    int sum=0;
    int maxPathval=INT_MIN;
  };
    int maxPathSum(TreeNode* root) 
    {
      struct pathData retval;
      if(root==NULL)
        return retval.maxPathval;
      retval=maxPath(root);
      return retval.maxPathval;  
    }
  struct pathData maxPath(TreeNode* root)
  {
    struct pathData retval;
    if(root==NULL)
      return retval;
    struct pathData left=maxPath(root->left);
    struct pathData right=maxPath(root->right);
    
    retval.sum=max(root->val,root->val+max(left.sum,right.sum));
    retval.maxPathval=max(retval.sum,max(left.maxPathval,right.maxPathval));
    retval.maxPathval=max(retval.maxPathval,root->val+left.sum+right.sum);
    
    return retval;
  }
};