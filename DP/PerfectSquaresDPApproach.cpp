class Solution {
public:
    int numSquares(int n) 
    {
        vector<int> dp(10000+1,INT_MAX);
        vector<int> squares;
        for(int i=1;i<=sqrt(n);i++)
        {
            squares.push_back(i*i);
        }
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(auto x:squares)
            {
                if(i-x<0)
                {
                    continue;
                }
                dp[i]=min(dp[i-x]+1,dp[i]);
            }
        }
        return dp[n];
    }
};