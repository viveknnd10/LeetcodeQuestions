#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) 
    {
      int n=nums.size();
      vector<int> dp(n,INT_MAX-2);
      dp[n-1]=0;
      for(int i=n-1;i>=0;i--)
      {
        for(int j=1;j<=nums[i];j++)
        {
          if(i+j<n)
            dp[i]=min(dp[i],dp[i+j]+1);
        }
      }
      return dp[0];
    }
};
int main()
    {
        vector<int> nums={2,3,0,1,4};
        Solution s;
        cout<<s.jump(nums);
    }