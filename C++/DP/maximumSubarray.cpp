#include<iostream>
#include<vector>
using namespace std;
//#include<algorithms>
int maxSubArray(vector<int>& nums) 
    {
      vector<vector<int> > dp(nums.size(),vector<int>(nums.size(),0));
      int maxSum=INT_MIN;
      for(int i=0;i<nums.size();i++)
      {
        for(int j=i;j>=0;j--)
        {
          if(j==i)
          {
            dp[i][j]=nums[i];
          }
          else
          {
            dp[i][j]=dp[i][i]+dp[i-1][j];
          }
          maxSum=max(dp[i][j],maxSum);
        }
      }
      for(int i=0;i<nums.size();i++)
      {
        for(int j=0;j<nums.size();j++)
        {
          cout<<dp[i][j]<<" ";
        }
        cout<<endl;
      }
      return maxSum;
    }
void main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;        
}