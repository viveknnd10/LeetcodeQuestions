class Solution {
public:
    int max_path=INT_MIN;
    int findMaxPath(Node* root)
    {
      if(!root)
        return 0;
      if(root->children.size()==0)
        return 1;
      vector<int> child_val(root->children.size(),0);
      for(int i=0;i<root->children.size();i++)
      {
        child_val[i]=findMaxPath(root->children[i]);
      }
      int max1=0,max2=0,index1=0;
      for(int i=0;i<child_val.size();i++)
      {
        if(child_val[i]>max1)
        {
          max1=child_val[i];
          index1=i;
        }
      }
      for(int i=0;i<child_val.size();i++)
      {
        if(child_val[i]>max2 && i!=index1)
          max2=child_val[i];
      }
      int current_max=1+max1+max2;
      max_path=max(max_path,current_max);
      return 1+max1;
    }
    int diameter(Node* root) 
    {
      if(root->children.size()==0)
        return 0;
      findMaxPath(root);
      return max_path-1;
    }
};