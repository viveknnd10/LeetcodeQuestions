class Solution {
  class disjointSet
  {
    int length=0;
    vector<int> root;
    vector<int> rank;
    public:
    disjointSet(int n)
    {
      root.resize(n,0);
      rank.resize(n,1);
      length=n;
    }
    void unionS()
    {
      for(int i=0;i<root.size();i++)
      {
        root[i]=i;
      }
      return;
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
    int getNoOfConnectedComponents()
    {
      return length;
    }
    void unionFind(int x,int y)
    {
      int rootA=find(x),rootB=find(y);
      if(rootA!=rootB)
      {
        if(rank[rootA]>rank[rootB])
        {
          root[rootB]=root[rootA];
        }
        else if(rank[rootA]<rank[rootB])
        {
          root[rootA]=root[rootB];
        }
        else
        {
          root[rootB]=root[rootA];
          rank[rootB]+=1;
          length-=1;
        }
      }
    }
  };
public:
    int earliestAcq(vector<vector<int>>& logs, int n) 
    {
      priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
      for(int i=0;i<logs.size();i++)
      {
        pq.push({logs[i][0],logs[i][1],logs[i][2]});
      }
      disjointSet ds(n);
      ds.unionS();
      while(!pq.empty())
      {
        auto [timestamp,x,y]=pq.top();
        pq.pop();
        ds.unionFind(x,y);
        int connectedComp=ds.getNoOfConnectedComponents();
        if(connectedComp==1)
        {
          return timestamp;
        }
      }
      return -1;
    }
};