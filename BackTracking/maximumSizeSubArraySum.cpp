/*ques>
Given an integer array nums and an integer k, return the maximum length of a subarray that sums to k. 
If there is not one, return 0 instead.

Example 1:

Input: nums = [1,-1,5,-2,3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
Example 2:

Input: nums = [-2,-1,2,1], k = 1
Output: 2
Explanation: The subarray [-1, 2] sums to 1 and is the longest.*/


class Solution {
public:
    int ans=0;
    void maxLength(vector<int>& nums,int k,int left,int right)
    {
      if(left<=right)
      {
        int sum=0;
        for(int i=left;i<=right;i++)
        {
          sum+=nums[i];
        }
        if(sum==k)
        {
          ans=max(ans,right-left+1);
          return;
        }
        else
        {
            maxLength(nums,k,left+1,right);
            maxLength(nums,k,left,right-1);
        }
        
      }
    }
    
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
      int left=0,right=nums.size()-1;
      maxLength(nums,k,left,right);
      return ans;
    }
};