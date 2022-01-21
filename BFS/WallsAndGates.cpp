class Solution {
 public:
  void wallsAndGates(vector<vector<int>> &rooms) {
    int m=rooms.size(),n=rooms[0].size();
    queue<pair<int,int>> q;
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(rooms[i][j]==0)
        {
          q.push({i,j});
        }
      }
    }
    vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty())
    {
      auto [row,column]=q.front();
      q.pop();
      for(auto [x1, y1] : dirs)
      {
        int x=row+x1,y=column+y1;
        if(x<0 || y<0 || x>=m || y>=n || rooms[x][y]!=2147483647)
        {
          continue;
        }
        rooms[x][y]=rooms[row][column]+1;
        q.push({x,y});
      }
    }
  }
};