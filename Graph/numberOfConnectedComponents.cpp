class Solution {
  class disjointSet
  {
    vector<int> root,rank;
    int ans=0;
    public:
    disjointSet(int n)
    {
      root.resize(n,0);
      rank.resize(n,1);
      ans=n;
    }
    void unions()
    {
      for(int i=0;i<root.size();i++)
      {
        root[i]=i;
      }
    }
    int find(int node)
    {
      if(root[node]==node)
        return node;
      else
        return root[node]=find(root[node]);
    }
    int getAns()
    {
      return ans;
    }
    void unionFind(int edge1,int edge2)
    {
      int root1=find(edge1),root2=find(edge2);
      if(root1!=root2)
      {
        if(rank[root1]>rank[root2])
          root[root1]=root2;
        else if(rank[root2]>rank[root1])
          root[root2]=root1;
        else
        {
          root[root2]=root1;
          rank[root2]+=1;
          ans--;
        }
      }
    }
  };
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
      disjointSet ds(n);
      ds.unions();
      for(auto edge:edges)
      {
        ds.unionFind(edge[0],edge[1]);
      }
      return ds.getAns();
    }
};