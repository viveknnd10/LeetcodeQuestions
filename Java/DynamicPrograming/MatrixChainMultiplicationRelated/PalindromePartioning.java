package Java.DynamicPrograming.MatrixChainMultiplicationRelated;

class Solution{
    static int[][] dp=new int[501][501];
    static Boolean isPalindrome(String str)
    {
        int i=0,j=str.length()-1;
        while(i<j)
        {
            if(str.charAt(i)==str.charAt(j))
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    static int MCM(String str,int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        if(isPalindrome(str.substring(i,j+1)))
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int ans=Integer.MAX_VALUE;
        for(int k=i;k<j;k++)
        {
            int left=0,right=0;
            if(dp[i][k]==-1)
            {
                dp[i][k]=MCM(str,i,k);
            }
            if(dp[k+1][j]==-1)
            {
                dp[k+1][j]=MCM(str,k+1,j);
            }
            left=dp[i][k];
            right=dp[k+1][j];
            int temp=1+left+right;
            ans=Math.min(temp,ans);
        }
        dp[i][j]=ans;
        return ans;
    }
    static int palindromicPartition(String str)
    {
        // code here
        if(str.length()==1)
        {
            return 0;
        }
        if(isPalindrome(str))
        {
            return 0;
        }
        for(int i=0;i<dp.length;i++)
        {
            Arrays.fill(dp[i],-1);
        }
        return MCM(str,0,str.length()-1);
    }
}
