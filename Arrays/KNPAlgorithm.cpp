#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> lpsMaking(string t)
    {
        int n=t.size();
        vector<int> lps(n,0);
        int i=1,j=0;
        while(i<n)
        {
            if(t[i]==t[j])
            {
                lps[i]=j+1;
                j++;
                i++;
            }
            else
            {
                if(t[i]!=t[j] && j>0)
                {
                    j=lps[j-1];
                }
                else
                {
                    i++;
                }
            }
        }
        return lps;
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
        string s="aaaaacaaaaaaaaaaaaa",t="aaacaaaa";
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