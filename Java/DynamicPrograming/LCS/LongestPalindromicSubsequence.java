package Java.DynamicPrograming.LCS;

class Solution {
    private int lcs(String text1,StringBuffer text2)
    {
        int n=text1.length(),m=text2.length();
        int[][] dp=new int[n+1][m+1];
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<m;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1.charAt(i-1)==text2.charAt(j-1))
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    public int longestPalindromeSubseq(String s) {
        StringBuffer sf=new StringBuffer(s);
        return lcs(s,sf.reverse());
    }
}
