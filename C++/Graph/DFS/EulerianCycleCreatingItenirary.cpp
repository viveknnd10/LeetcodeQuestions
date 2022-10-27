class Solution {
public:
  struct LessThanForStrings
  {
    bool operator()(const string& lhs, const string& rhs) const
    {
      return lhs>rhs;
    }
  };
  vector<string> ans;
  void dfs(string source,unordered_map<string,priority_queue<string,vector<string>,LessThanForStrings>>& q)
  {
    while(!q[source].empty())
    {
      string sour=q[source].top();
      q[source].pop();
      dfs(sour,q);
    }
    ans.push_back(source);
    return;
  }
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
      unordered_map<string,priority_queue<string,vector<string>,LessThanForStrings>> q;
      for(auto edge:tickets)
      {
          q[edge[0]].push(edge[1]);
      }
      string source="JFK";
      dfs(source,q);
      reverse(ans.begin(),ans.end());
      return ans;
    }
};