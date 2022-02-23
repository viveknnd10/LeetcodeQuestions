class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) 
    {
      priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
      for(int i=0;i<workers.size();i++)
      {
        for(int j=0;j<bikes.size();j++)
        {
          int dis=abs(abs(workers[i][0]-bikes[j][0])+abs(workers[i][1]-bikes[j][1]));
          q.push({dis,i,j});
        }
      }
      int n=workers.size(),m=bikes.size();
      vector<int> ans(n,-1);
      vector<int> bike(m,-1);
      while(!q.empty())
      {
        auto [distance,x,y]=q.top();
        q.pop();
        if(ans[x]>-1)
        {
          continue;
        }
        else if(bike[y]==-1)
        {
          ans[x]=y;
          bike[y]=x;
        }
      }
      return ans;
    }
};