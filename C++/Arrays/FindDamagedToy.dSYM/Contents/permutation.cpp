class Solution {
public:
    void help(vector<vector<int>>& ans, vector<int> temp,vector<int> nums,int i)
    {
        temp.push_back(nums[i]);
        nums.erase(nums.begin()+i);
        if(nums.empty())
        {
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<nums.size();j++)
        {
            help(ans,temp,nums,j);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> temp;
            help(ans,temp,nums,i);
        }
        return ans;
    }
};