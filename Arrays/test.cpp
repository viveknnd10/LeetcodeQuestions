#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums,int k) 
    {
      int n=nums.size();
      vector<int> dp(n,INT_MIN+2);
      dp[n-1]=nums[0];
      for(int i=n-1;i>=0;i--)
      {
        for(int j=1;j<=k;j++)
        {
          if(i+j<n)
            dp[i]=max(dp[i],dp[i]+nums[j]);
        }
      }
      return dp[0];
    }
};
int main()
    {
        vector<int> nums={3,4,-2,1,2};
        Solution s;
        int k=3;
        cout<<s.jump(nums,k);
    }