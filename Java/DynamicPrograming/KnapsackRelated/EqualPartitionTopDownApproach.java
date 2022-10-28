package Java.DynamicPrograming.KnapsackRelated;

class Solution {
    private boolean subsetSum(int[] nums,int w,int n)
    {
        boolean[][] dp=new boolean[n+1][w+1];
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<=w;i++)
        {
            dp[0][i]=false;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(nums[i]<=j)
                {
                    dp[i][j]=dp[i-1][j-nums[i]]||dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][w];
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
        return subsetSum(nums,totalSum,n-1);   
    }
}
