class Solution {
public:
    int minCost(vector<vector<int>>& costs) 
    {
      vector<int> curr(3,0),prev(3,0);
      for(auto a:costs)
      {
        curr[0]=a[0]+min(prev[1],prev[2]);
        curr[1]=a[1]+min(prev[0],prev[2]);
        curr[2]=a[2]+min(prev[1],prev[0]);
        curr.swap(prev);
      }
      return min(min(prev[0],prev[1]),prev[2]);
        
    }
};