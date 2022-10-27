/* time limit exceeds*/

class Solution {
public:
    bool DFS(int n,vector<vector<int>>& edges,vector<int>& visited,int start,int destination)
    {
      bool flag=true,ans=false;
      if(start==destination)
        return true;
      for(auto x:visited)
      {
        if(x==0)
        {
          flag=false;
          break;
        }
      }
      if(flag)
        return false;
      for(auto x:edges)
      {
        if(x[0]==start && !(visited[x[1]]))
        {
          visited[x[0]]=1;
          ans=DFS(n,edges,visited,x[1],destination);
          if(ans)
            return ans;
        }
      }
      return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
      if(source==destination)
        return true;
       vector<vector<int>> adjacency_list;
      for (auto edge : edges)
      {
        adjacency_list.push_back({edge[0],edge[1]});
        adjacency_list.push_back({edge[1],edge[0]});
      }
      bool ans=false;
      for(auto vertex:adjacency_list)
      {
        if(vertex[0]==source)
        {
          cout<<"debug"<<"\n";
          vector<int> visited(n,0);
          visited[vertex[0]]=1;
          ans=DFS(n,adjacency_list,visited,vertex[1],destination);
          if(ans)
            return ans;
        }
      }
      return ans;
    }
};