class Solution {
  class disjointSet
  {
    private:
        vector<int> root;
        vector<int> rank;
        int ans=0;
    public:
    disjointSet(int n)
    {
      root.resize(n,0);
      rank.resize(n,0);
      ans=n;
    }
    int getAns()
    {
      return ans;
    }
    void unions()
    {
      for(int i=0;i<root.size();i++)
      {
        root[i]=i;
        rank[i]=1;
      }
      return;
    }
    int find(int x)
    {
      
      cout<<x<<"debug2"<<endl;
      if(root[x]==x)
        return x;
      else
        return root[x]=find(root[x]);
    }
    bool unionFind(int x,int y)
    {
      cout<<"debug1"<<endl;
      int rootX=find(x),rootY=find(y);
      if(rootX==rootY)
        return false;
      else
      {
        if(rank[rootX]>rank[rootY])
          root[rootX]=rootY;
        else if(rank[rootX]<rank[rootY])
          root[rootY]=rootX;
        else
        {
          root[rootY]=rootX;
          rank[rootY]+=1;
          ans--;
        }
      }
      return true;
    }
  };
public:
    bool validTree(int n, vector<vector<int>>& edges) 
    {
      disjointSet ds(n);
      ds.unions();
      for(auto edge:edges)
      {
        cout<<edge[0]<<"   "<<edge[1]<<endl;
        if(!ds.unionFind(edge[0],edge[1]))
        {
          return false;
        }
      }
      if(ds.getAns()==1)
        return true;
      return false;
    }
};