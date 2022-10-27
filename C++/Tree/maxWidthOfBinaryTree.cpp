class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
      long long maxWidth=INT_MIN;
      queue<pair<TreeNode*,long long>> q;
      q.push({root,0});
      while(!q.empty())
      {
        int length=q.size();
        int min=q.front().second;
        long long leftmost=0,rightmost=0;
        for(int i=0;i<length;i++)
        {
          auto [currNode,x]=q.front();
          x=x-min;
          q.pop();
          if(i==0 && length>1)
          {
            leftmost=x;
          }
          if(i==length-1 && i!=0)
          {
            rightmost=x;
          }
          if(currNode->left)
            q.push({currNode->left,(long long)(x*2)+1});
          if(currNode->right)
            q.push({currNode->right,(long long)(x*2)+2});
        }
        long long currWidth=0;
        if(length==1)
        {
          currWidth=1;
        }
        else
        {
          currWidth=abs(rightmost-leftmost+1);
        }
        maxWidth=max(currWidth,maxWidth);
      }
      return maxWidth;
        
    }
};