class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<vector<int>> dp(amount+1,vector<int>(coins.size()+1,0) );
        for(int i=0;i<=amount;i++)
        {
            for(int j=0;j<=coins.size();j++)
            {
                if(i==0)
                {
                    dp[i][j]=1;
                }
                else if(j==0)
                {
                    dp[i][j]=0;
                }
                else
                    dp[i][j]=dp[i][j-1]+(coins[j-1]<=i?dp[i-coins[j-1]][j]:0);
            }
        }
        return dp[amount][coins.size()];
    }
};