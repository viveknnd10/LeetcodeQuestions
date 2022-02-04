class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(mp.find(sum)!=mp.end())
            {
                ans=max(ans,i-mp[sum]);
                continue;
            }
            mp[sum]=i;
        }
        return ans;
    }
};