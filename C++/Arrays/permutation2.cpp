class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
      sort(nums.begin(),nums.end());
      vector<vector<int>> ans;
      set<vector<int>> s;
      s.insert(nums);
      ans.push_back(nums);
      while(next_permutation(nums.begin(),nums.end()))
      {
        if(s.find(nums)==s.end())
        {
          ans.push_back(nums);
        }
      }
      return ans;
      
    }
};