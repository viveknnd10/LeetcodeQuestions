#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int val;
  vector<Node *> children;
    Node(int x) : val(x) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
      vector<vector<int>> ans;
      if(!root)
        return ans;
      queue<Node*> q;
      q.push(root);
      while(!q.empty())
      {
        int length=q.size();
        vector<int> curr;
        cout<<"debug"<<endl;
        for(int i=0;i<length;i++)
        {
          Node* temp=q.front();
          curr.push_back(temp->val);
          cout<<temp->children.size()<<endl;
          q.pop();
          for(int j=0;j<temp->children.size();j++)
          {
            if(temp->children[j])
              q.push(temp->children[j]);
          }
        }
        ans.push_back(curr);
      }
      return ans;  
    }
};

int main()
{
    Node* root=new Node(1);
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));
    root->children.push_back(new Node(5));
    root->children.push_back(new Node(6));
    root->children.push_back(new Node(7));
    root->children.push_back(new Node(8));
    root->children.push_back(new Node(9));
    root->children.push_back(new Node(10));
    root->children.push_back(new Node(11));
    root->children.push_back(new Node(12));
    root->children.push_back(new Node(13));
    root->children.push_back(new Node(14));
    root->children.push_back(new Node(15));
    root->children.push_back(new Node(16));
    root->children.push_back(new Node(17));
    root->children.push_back(new Node(18));
    root->children.push_back(new Node(19));
    root->children.push_back(new Node(20));
    root->children.push_back(new Node(21));
    root->children.push_back(new Node(22));
    root->children.push_back(new Node(23));
    root->children.push_back(new Node(24));
    root->children.push_back(new Node(25));
    root->children.push_back(new Node(26));
    root->children.push_back(new Node(27));
    root->children.push_back(new Node(28));
    root->children.push_back(new Node(29));
    root->children.push_back(new Node(30));
    root->children.push_back(new Node(31));
    root->children.push_back(new Node(32));
    root->children.push_back(new Node(33));
    root->children.push_back(new Node(34));
    root->children.push_back(new Node(35));
    root->children.push_back(new Node(36));
    root->children.push_back(new Node(37));
    root->children.push_back(new Node(38));
    root->children.push_back(new Node(39));
    vector<vector<int>> ans=Solution().levelOrder(root);
    for(int i=0;i<ans.size();i++)
    {
      for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
      cout<<endl;
    }
}