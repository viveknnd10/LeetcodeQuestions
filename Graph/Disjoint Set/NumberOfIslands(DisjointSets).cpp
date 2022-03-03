class Solution {
public:
    vector<int> root,rank;
    int ans=0;
    void unions(int n){
        ans = n;
        rank.resize(n), root.resize(n);
        for(int i= 0; i<n; i++) {
            rank[i] = 1, root[i] = i;
        }
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
      int rootX=find(x),rootY=find(y);
      if(rootX!=rootY)
      {
        if(rank[rootX]>rank[rootY])
        {
          root[rootX]=rootY;
        }
        else if(rank[rootX]<rank[rootY])
        {
          root[rootY]=rootX;
        }
        else
        {
          root[rootY]=rootX;
          rank[rootY]+=1;
          ans--;
        }
      }
      return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unions(n);
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++)
            {
                if(isConnected[i][j]==1)
                {
                  unionFind(i, j);
                }
            }
        }
        return ans;
    }
};