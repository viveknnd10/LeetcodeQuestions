class Solution {
  vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
  class disjointSet
  {
    vector<int> rank,root;
    int con_comp=0;
    public:
    disjointSet(int n)
    {
      rank.resize(n,0);
      root.resize(n,-1);
      //con_comp=n;
    }
    void setParent(int x)
    {
      root[x]=x;
      con_comp++;
    }
    int find(int x)
    {
      if(root[x]==x)
      {
        return x;
      }
      else
        return root[x]=find(root[x]);
    }
    void unionFind(int x,int y)
    {
      int rootX=find(x),rootY=find(y);
      if(rootX!=rootY)
      {
        if(rank[rootX]>rank[rootY])
        {
          root[rootY]=rootX;
        }
        else if(rank[rootY]>rank[rootX])
        {
          root[rootX]=rootY;
        }
        else
        {
          root[rootY]=rootX;
          rank[rootY]+=1;
        }
        con_comp-=1;
      }
    }
    bool istrue(int x)
    {
      return root[x]>=0;
    }
    int getConComp()
    {
      return con_comp;
    }
  };
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) 
    {
      disjointSet ds(m*n);
      vector<int> ans;
      set<pair<int,int>> temp;
      for(auto edge:positions)
      {
        if(temp.find({edge[0],edge[1]})!=temp.end())
        {
          ans.push_back(ds.getConComp());
          continue;
        }
        temp.insert({edge[0],edge[1]});
        int x=edge[0],y=edge[1];
        vector<int> overlap;
        for(auto [dirx,diry]:directions)
        {
          int newX=x+dirx,newY=y+diry;
          if(newX<0 || newY<0 || newX>=m || newY>=n)
            continue;
          if(ds.istrue(newX*n+y))
            overlap.push_back(newX*n+y);
          if(ds.istrue(x*n+newY))
            overlap.push_back(x*n+newY);
        }
        int index=x*n+y;
        ds.setParent(index);
        for(int i:overlap)
          {
            ds.unionFind(i,index);
          }
        ans.push_back(ds.getConComp());
      }
      return ans;
    }
};