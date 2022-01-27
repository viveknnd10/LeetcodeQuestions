class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
      map<int,int> count;
      vector<int> result;
      for(int i=0;i<nums.size();i++)
      {
        auto temp=count.find(nums[i]);
        if(temp!=count.end())
        {
          (temp->second)++;
        }
        else
        {
          count.insert({nums[i],1});
        }
      }
      priority_queue<pair<int,int>> pq;
      for(auto i=count.begin();i!=count.end();i++)
      {
        auto [x1,y1]=*i;
        pq.push({y1,x1});
      }
      for(int i=0;i<k;i++)
      {
        auto [x1,y1]=pq.top();
        result.push_back(y1);
        pq.pop();
      }
      return result;
        
    }
};