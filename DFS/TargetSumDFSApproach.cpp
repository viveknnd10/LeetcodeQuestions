ques>You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
EXAMPLE 1>
    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3
    Return the number of different expressions that you can build, which evaluates to target.
class Solution {
public:
    int count=0;
    void DFS(vector<int>& nums,int sum,int i,int target)
    {
        if(i==nums.size())
        {
            if(sum==target)
            {
                count+=1;
            }
            return;
        }
        DFS(nums,sum+nums[i],i+1,target);
        DFS(nums,sum-nums[i],i+1,target);
        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        if(nums.size()==0 && nums[0]==target)
        {
            return 1;
        }
        int i=0,sum=0;
        DFS(nums,sum,i,target);
        return count;
        
    }
};
