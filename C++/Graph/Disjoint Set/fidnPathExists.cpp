class Solution {
  class disjointSet
  {
    vector<int> rank;
    vector<int> root;
    public:
    disjointSet(int n)
    {
      rank.resize(n,1);
      root.resize(n,0);
      for(int i=0;i<n;i++)
        root[i]=i;
    }
    int find(int x)
    {
      if(root[x]==x)
        return x;
      else
        return root[x]=find(root[x]);
    }
    void unionFind(int x,int y)
    {
      int rootA=find(x),rootB=find(y);
      if(rootA!=rootB)
      {
        if(rank[rootA]>rank[rootB])
          root[rootB]=rootA;
        else if(rank[rootB]>rank[rootA])
          root[rootA]=rootB;
        else
        {
          root[rootB]=rootA;
          rank[rootB]+=1;
        }
      }
      return;
    }
  };
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
      disjointSet ds(n);
      for(auto edge:edges)
      {
        ds.unionFind(edge[0],edge[1]);
      }
      if(ds.find(source)==ds.find(destination))
        return true;
      else
        return false;
        
    }
};