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