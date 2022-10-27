ques>Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
      for(int n:nums)
      {
        int index=abs(n)-1;
        if(nums[index]>0)
        {
          nums[index]=-1*nums[index];
        }
      }
      vector<int> ans;
      for(int i=0;i<nums.size();i++)
      {
        if(nums[i]>0)
        {
          ans.push_back(i+1);
        }
      }
      return ans;
    }
};