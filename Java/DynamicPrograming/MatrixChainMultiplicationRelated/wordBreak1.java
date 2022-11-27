package Java.DynamicPrograming.MatrixChainMultiplicationRelated;

class Solution {
    private boolean MCM(String s,HashMap<String,Boolean> dict,int i,int j,int[][] dp)
    {
        boolean temp=false;
        if(i>j)
            return false;   
        if(dict.containsKey(s.substring(i,j+1)))
        {
            return true;
        }
        if(dp[i][j]>-1)
        {
            return (dp[i][j]==1)?true:false;
        }
        for(int k=i;k<j;k++)
        {
            temp = (temp || (MCM(s,dict,i,k,dp)&&MCM(s,dict,k+1,j,dp)));
            dp[i][j]=(temp)?1:0;
            if(temp==true)
                break;
        }
        return temp;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        HashMap<String,Boolean> dict=new HashMap<String,Boolean>();
        for(String word:wordDict)
        {
            dict.put(word,true);
        }
        int[][] dp=new int[s.length()+1][s.length()+1];
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;j<s.length();j++)
            {
                dp[i][j]=-1;
            }
        }
        return MCM(s,dict,0,s.length()-1,dp);
    }
}
