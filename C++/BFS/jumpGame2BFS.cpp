#include <bits/stdc++.h>
using namespace std;
int jump(vector<int>& nums) 
    {
      if(nums.size()==1)
      {
        return 0;
      }
      queue<pair<int,int>> q;
      q.push({0,0});
      while(!q.empty())
      {
        auto [index,noJump]=q.front();
        q.pop();
        for(int i=1;i<=nums[index];i++)
        {
          if(index+i==nums.size()-1)
          {
            return noJump+1;
          }
          if(index+i<nums.size()-1)
          {
            q.push({index+i,noJump+1});
          }
        }
      }
      return -1;
    }

int main()
{
  vector<int> nums={2,3,0,1,4};
  cout<<jump(nums);
}