class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) 
    {
      int ans=0,sum=0;
      unordered_map<int,int> runningSum;
      for(int i=0;i<nums.size();i++)
      {
        sum+=nums[i];
        if(sum==k)
          ans=max(ans,i+1);
        else if(runningSum.find(sum-k)!=runningSum.end())
          ans=max(ans,i-runningSum[sum-k]+1);
        if(runningSum.find(sum)==runningSum.end())
          runningSum[sum]=i+1;
      }
      return ans;
    }
};