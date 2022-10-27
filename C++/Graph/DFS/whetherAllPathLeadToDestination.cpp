class Solution {
public:
  bool flag=true;
  bool dfs(int n, vector<vector<int>>& graph,vector<int>& visited,int source, int destination)
  {
    for(int neighbour:graph[source])
    {
      if(neighbour==source)
      {
        flag=false;
        return false;
      }
    }
    if(source==destination && graph[source].size()==0)
      return true;
    else if(source==destination && graph[source].size()>0)
      return false;
    if(graph[source].size()==0 ||(graph[source].size()==1 && visited[graph[source][0]]==1))
    {
      flag=false;
      return flag;
    }
    visited[source]=1;
    for(int neighbour:graph[source])
    {
      if(!visited[neighbour])
      {
        if(!dfs(n,graph,visited,neighbour,destination))
        {
          flag=false;
        }
      }
    }
    return flag;
  }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) 
    {
      if(source==destination && edges.size()>0)
        return false;
      vector<vector<int>> graph(n);
      for(auto edge:edges)
      {
        graph[edge[0]].push_back(edge[1]);
      }
      vector<int> visited(n,0);
      dfs(n,graph,visited,source,destination);
      return flag;
    }
};