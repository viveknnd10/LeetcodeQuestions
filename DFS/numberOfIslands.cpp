void DFS(vector<vector<char>>& grid,int i,int j)
  {
    if(grid[i][j]=='0')
    {
      return;
    }
    grid[i][j]='0';
    if(i+1<grid.size())
       DFS(grid,i+1,j);
    if(j+1<grid[0].size())
       DFS(grid,i,j+1);
    if(i-1>=0)
       DFS(grid,i-1,j);
    if(j-1>=0)
       DFS(grid,i,j-1);
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
            DFS(grid,i,j);
            count++;
          }
        }
      }
      return count;
    }