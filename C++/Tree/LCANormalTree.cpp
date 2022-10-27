class Solution {
public:
    TreeNode* ans;
    bool recurse(TreeNode* root,TreeNode* p,TreeNode* q)
    {
      if(root==NULL)
      {
        return false;
      }
      int left=recurse(root->left,p,q)?1:0;
      int right=recurse(root->right,p,q)?1:0;
      int mid=(root==p || root==q)?1:0;
      if(mid+left+right==2)
      {
        ans=root;
      }
      return(mid+left+right>0);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
      recurse(root,p,q);
      return ans;    
    }
};