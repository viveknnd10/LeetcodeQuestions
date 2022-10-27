class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int source,int destination,vector<int> visited,vector<vector<int>>& graph,vector<int> path)
    {
      path.push_back(source);
      if(source==destination)
      {
        ans.push_back(path);
        return;
      }
      if(visited[source])
        return;
      visited[source]=1;
      for(auto neighbour:graph[source])
      {
        if(!visited[neighbour])
          dfs(neighbour,destination,visited,graph,path);
      }
      return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
      int n=graph.size();
      vector<int> visited(n,0);
      vector<int> path;
      dfs(0,n-1,visited,graph,path);
      return ans;
    }
};