class Solution {
public:
  //nums = [-2,1,-3,4,-1,2,1,-5,4]
    int maxSubArray(vector<int>& nums) 
    {
      int current=nums[0],maxSum=nums[0];
      for(int i=1;i<nums.size();i++)
      {
        current=max(nums[i],current+nums[i]);
        maxSum=max(current,maxSum);
      }
      return maxSum;
    }
};