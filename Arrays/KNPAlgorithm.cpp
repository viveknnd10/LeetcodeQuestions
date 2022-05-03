#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> lps(string s)
    {
        int n=s.length();
        vector<int> dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(s[i]==s[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp;
    }
    bool knp(string s,string t)
    {
        int n=s.size(),m=t.size();
        vector<int> lps=lpsMaking(t);
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                  j=lps[j-1];
                else
                  i++;
            }
        }
        if(j==m)
          return true;
        return false;
    }
};
int main()
    {
        string s="aaaaacaaaaaaaaaaaaa",t="aacecaaaa";
        Solution p;
        vector<int> lps=p.lpsMaking(t);
        for(int i=0;i<lps.size();i++)
        {
            cout<<lps[i]<<" ";
        }
        cout<<endl;
        cout<<"debug"<<p.knp(s,t)<<endl;
        return 0;
    }