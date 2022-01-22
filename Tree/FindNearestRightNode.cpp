class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) 
    {
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty())
      {
        int size=q.size();
        vector<TreeNode *> v;
        for(int i=0;i<size;i++)
        {
          TreeNode *temp=q.front();
          q.pop();
          v.push_back(temp);
          if(temp->left)
          {
            q.push(temp->left);
          }
          if(temp->right)
          {
            q.push(temp->right);
          }
        }
        for(int i=0;i<v.size();i++)
        {
          if(v[i]->val==u->val && i+1<v.size())
          {
            return v[i+1];
          }
          else
          {
            NULL;
          }
        }
        cout<<endl;
      }
     return NULL;   
    }
};