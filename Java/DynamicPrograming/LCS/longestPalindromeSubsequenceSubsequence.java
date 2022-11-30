package Java.DynamicPrograming.LCS;

class Solution {
    private String LCS(String s1, String s2)
    {
        int l1=s1.length(),l2=s2.length();
        int[][] dp=new int[l1+1][l2+1];
        for(int i=0;i<=l1;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=l2;i++)
        {
            dp[0][i]=0;
        }
        for(int i=1;i<=l1;i++)
        {
            for(int j=1;j<=l2;j++)
            {
                if(s1.charAt(i-1)==s2.charAt(j-1))
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=l1,j=l2;
        String ans="";
        while(l1>0 && l2>0)
        {
            if(s1.charAt(l1-1)==s2.charAt(l2-1))
            {
                ans+=s1.charAt(l1-1);
                l1--;
                l2--;
            }
            else if(dp[l1-1][l2]<dp[l1][l2-1])
            {
                l2--;
            }
            else
            {
                l1--;
            }
        }
        System.out.println(ans);
        StringBuffer str=new StringBuffer(ans);
        str.reverse();
        return str.toString();
    }
    public String longestPalindrome(String s) 
    {
        StringBuffer str=new StringBuffer(s);
        str.reverse();
        return LCS(s,str.toString());
    }
}
