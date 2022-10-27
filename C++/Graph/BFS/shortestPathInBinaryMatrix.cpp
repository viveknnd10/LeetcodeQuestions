#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
      int m=grid.size(),n=grid[0].size();
      vector<vector<int>> visited(m,vector<int>(n,0));
      queue<tuple<int,int,int>> q;
      if(grid[0][0]==0)
      {
        q.push({0,0,0});
        visited[0][0]=1;
      }
      else
        return -1;
      while(!q.empty())
      {
        cout<<"debug"<<endl;
        auto [currX,currY,length]=q.front();
        q.pop();
        if(currX==m-1 && currY==n-1 && grid[currX][currY]==0)
        {
          return length+1;
        }
        else if(currX==m-1 && currY==n-1 && grid[currX][currY]==1)
        {
          return -1;
        }
        for(auto [x,y]:directions)
        {
          int newX=currX+x,newY=currY+y;
          if(newX<0 || newY<0 || newX>=m || newY>=n || visited[newX][newY]==1)
          {
            continue;
          }
          if(grid[newX][newY]==0)
          {
            q.push({newX,newY,length+1});
            visited[newX][newY]=1;
          }
        }
      }
      return -1;
    }
};

int main()
{
    vector<vector<int>> grid={{0,0,0},{1,1,0},{1,1,0},{0,0,0}};
    Solution s;
    cout<<s.shortestPathBinaryMatrix(grid);
}