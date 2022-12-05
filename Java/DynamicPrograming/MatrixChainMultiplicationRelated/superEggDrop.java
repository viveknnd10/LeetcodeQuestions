package Java.DynamicPrograming.MatrixChainMultiplicationRelated;

class Solution {
    private int eggDrop(int k,int n,int dp[][])
    {
       if(k==1)
            return n;
        if(n==1||n==0)
            return n;
        if(dp[k][n]!=-1)
            return dp[k][n];
        int mx=Integer.MAX_VALUE;
        for(int i=1;i<=n;i++)
        {
            int left,right;
            if(dp[k-1][i-1]!=-1)
            {
                left=dp[k-1][i-1];
            } else{
                dp[k-1][i-1]=eggDrop(k-1,i-1,dp);
                left=dp[k-1][i-1];
            }
            if(dp[k][n-i]!=-1)
            {
                right=dp[k][n-i];
            } else{
                dp[k][n-i]=eggDrop(k,n-i,dp);
                right=dp[k][n-i];
            }
            int temp=1+Math.max(left,right);
            mx=Math.min(mx,temp);
        }
        dp[k][n]=mx;
        return mx; 
    }
    public int superEggDrop(int k, int n) {
        int dp[][]=new int[101][10001];
        for(int i=0;i<101;i++)
        {
            Arrays.fill(dp[i],-1);
        }
        return eggDrop(k,n,dp);
    }
}
