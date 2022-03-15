class Solution {
  class DisjointSet
  {
    vector<int> rank;
    vector<int> root;
    int conComp=0;
    public:
    DisjointSet(int n)
    {
      rank.resize(n,1);
      root.resize(n,0);
      for(int i=0;i<n;i++)
        root[i]=i;
      conComp=n;
    }
    int find(int x)
    {
      if(root[x]==x)
      {
        return x;
      }
      else
      {
        return root[x]=find(root[x]);
      }
    }
    void unionFind(int x,int y)
    {
      int rootX=find(x),rootY=find(y);
      if(rootX!=rootY)
      {
        if(rank[rootX]>rank[rootY])
          root[rootY]=rootX;
        else if(rank[rootY]>rank[rootX])
          root[rootX]=rootY;
        else
        {
          root[rootY]=rootX;
          rank[rootY]+=1;
          conComp--;
        }
      }
      return;
    }
  };
public:
    int ManhattanDistance(int x1,int y1,int x2,int y2)
    {
      return abs(x2-x1)+abs(y2-y1);
    }
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
      vector<tuple<int,int,int>> edges;
      for(int i=0;i<points.size();i++)
      {
        for(int j=i+1;j<points.size();j++)
        {
          edges.push_back({ManhattanDistance(points[i][0],points[i][1],points[j][0],points[j][1]),i,j});
        }
      }
      sort(edges.begin(),edges.end());
      int count=0,n=edges.size(),cost=0;
      DisjointSet ds(n+1);
      for(auto [weight,x,y]:edges)
      {
        if(ds.find(x)!=ds.find(y))
        {
          ds.unionFind(x,y);
          cost+=weight;
          count++;
        }
        if(count==n)
          break;
      }
      cout<<cost;
      return cost; 
    }
};