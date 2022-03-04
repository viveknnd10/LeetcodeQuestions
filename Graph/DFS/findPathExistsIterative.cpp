class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
      vector<bool> visited(n,false);
      vector<vector<int>> adjacency_list(n);
      for(auto edge:edges)
      {
        adjacency_list[edge[0]].push_back(edge[1]);
        adjacency_list[edge[1]].push_back(edge[0]);
      }
      stack<int> st;
      st.push(source);
      while(!st.empty())
      {
        int temp=st.top();
        cout<<temp<<endl;
        st.pop();
        if(temp==destination)
          return true;
        if(visited[temp])
          continue;
        visited[temp]=true;
        for(auto neighbour:adjacency_list[temp])
          st.push(neighbour);
      }
      return false;
    }
};