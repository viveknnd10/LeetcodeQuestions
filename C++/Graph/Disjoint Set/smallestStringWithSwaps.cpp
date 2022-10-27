class Solution {
public:
    class disjointSet
    {
      vector<int> rank;
      vector<int> root;
      int connComp=0;
      public:
      disjointSet(int n)
      {
        connComp=n;
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
            connComp--;
          }
        }
      }
      int getconnComp()
      {
        return connComp;
      }
      vector<int> getRoot()
      {
        return root;
      }
    };
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
      string ans="";
      int n=s.size();
      disjointSet ds(n);
      for(int i=0;i<pairs.size();i++)
      {
        ds.unionFind(pairs[i][0],pairs[i][1]);
      }
      int connComp=ds.getconnComp();
      if(connComp==1)
      {
        sort(s.begin(),s.end());
        return s;
      }
      else
      {
        vector<int> root=ds.getRoot();
        map<int,string> temp;
        for(int i=0;i<root.size();i++)
        {
          int m=ds.find(i);
          temp[m].push_back(s[i]);
        }
        for(auto& [x,y]:temp)
        {
          sort(y.begin(),y.end(),greater<>());
        }
        for(int i=0;i<root.size();i++)
        {
          int p=ds.find(i);
          cout<<i<<"------"<<p<<" ";
          s[i]=temp[p].back();
          temp[p].pop_back();
        }
      }
      return s;
    }
};