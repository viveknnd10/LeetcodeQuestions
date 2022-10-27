#include<bits/stdc++.h>
using namespace std;
class TreeNode
{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        val=0;
        left=NULL;
        right=NULL;
    }
    TreeNode(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
};
vector<vector<int> > ans;
class Solution {
public:
    int getHeight(TreeNode *root)
    {
      if(!root)
        return -1;
      int leftHeight=getHeight(root->left);
      int rightHeight=getHeight(root->right);
      int currHeight=max(leftHeight,rightHeight)+1;
      if(ans.size()<=currHeight)
        ans.push_back({});
      ans[currHeight].push_back(root->val);
      return currHeight;
    }
    vector<vector<int> > findLeaves(TreeNode* root) 
    {
      getHeight(root);
      return ans;
    }
};

int main()
{
    Solution s;
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    s.findLeaves(root);
    for(auto i:s.ans)
    {
      for(auto j:i)
        cout<<j<<" ";
      cout<<endl;
    }
    return 0;
}