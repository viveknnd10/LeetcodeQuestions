class Solution {
public:
  void BFS(vector<vector<char>>& grid,int i,int j)
  {
    int m=grid.size(),n=grid[0].size();
    vector<pair<int,int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    queue<pair<int,int>> q;
    q.push({i,j});
    grid[i][j]='0';
    while(!q.empty())
    {
      auto [r,c]=q.front();
      for(auto [x,y]:dirs)
      {
        int row=r+x,column=c+y;
        if(row<0 || column <0 || row>=m || column>=n ||grid[row][column]!='1')
        {
          continue;
        }
        grid[row][column]='0';
        q.push({row,column});
      }
      q.pop();
    }
  }
    int numIslands(vector<vector<char>>& grid) 
    {
      int m=grid.size(),n=grid[0].size(),count=0;
      for(int i=0;i<m;i++)
      {
        for(int j=0;j<n;j++)
        {
          if(grid[i][j]=='1')
          {
            BFS(grid,i,j);
            count++;
          }  
        }
      }
      cout<<count;
      return count;
    }
};