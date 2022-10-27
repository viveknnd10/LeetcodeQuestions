class Solution {
    private boolean subsetSum(int[] nums,int[][] dp,int w,int n)
    {
        if(w==0)
        {
            return true;
        }
        if(n==0 && w>0)
        {
            return false;
        }
        if(dp[n][w]!=-1)
        {
            if(dp[n][w]==0)
                return false;
            else
                return true;
        }
        if(nums[n]<=w)
        {
            dp[n][w]=(subsetSum(nums,dp,w-nums[n],n-1)||subsetSum(nums,dp,w,n-1))?1:0;
            if(dp[n][w]==0)
                return false;
            else
                return true;
        }
        dp[n][w]=subsetSum(nums,dp,w,n-1)?1:0;
        if(dp[n][w]==0)
            return false;
        else
            return true;
    }
    public boolean canPartition(int[] nums) {
        int totalSum=0,n=nums.length;
        for(int i=0;i<nums.length;i++)
        {
            totalSum+=nums[i];
        }
        if(totalSum%2!=0)
        {
            return false;
        }
        totalSum/=2;
        int[][] dp=new int[n+1][totalSum+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=totalSum;j++)
            {
                dp[i][j]=-1;
            }
        }
        return subsetSum(nums,dp,totalSum,n-1);   
    }
}