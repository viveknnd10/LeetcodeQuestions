class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
      int n=s.size();
      vector<bool> dp(n+1,false);
      dp[n]=true;
      for(int i=n-1;i>=0;i--)
      {
        for(auto x:wordDict)
        {
          int m=x.size();
          if(i+m<=n)
          {
            if(s.substr(i,m)==x)
            {
              dp[i]=dp[i+m];
            }
            if(dp[i])
              break;
          }
        }
      }
      for(int i=0;i<dp.size();i++)
      {
        cout<<dp[i]<<" ";
      }
    return dp[0];
    }
  };