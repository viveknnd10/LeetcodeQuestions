package Java.DynamicPrograming.LCS;

class Solution {
    private int lcs(String text1,String text2,int[][] dp)
    {
        int n=text1.length(),m=text2.length();
        if(text1.length() == 0 || text2.length() == 0)
            return 0;
        if(dp[n][m]>-1)
        {
            return dp[n][m];
        }
        else if(text1.charAt(n-1)==text2.charAt(m-1))
        {
            dp[n][m]= 1+lcs(text1.substring(0,n-1),text2.substring(0,m-1),dp);
        }
        else
        {
            dp[n][m] = Math.max(lcs(text1.substring(0,n-1),text2,dp),lcs(text1,text2.substring(0,m-1),dp));
        }
        return dp[n][m];
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int n=text1.length(),m=text2.length();
        int[][] dp=new int[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=-1;
            }
        }
        return lcs(text1,text2,dp);
    }
}
