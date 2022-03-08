/*An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

 

Example 1:

Input: changed = [1,3,4,2,6,8]
Output: [1,3,4]
Explanation: One possible original array could be [1,3,4]:
- Twice the value of 1 is 1 * 2 = 2.
- Twice the value of 3 is 3 * 2 = 6.
- Twice the value of 4 is 4 * 2 = 8.
Other original arrays could be [4,3,1] or [3,1,4].
Example 2:

Input: changed = [0,0,0,0]
Output: [0,0]
Explanation: changed is not a doubled array.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
      unordered_map<int,int> s;
      for(int i=0;i<changed.size();i++)
      {
        s[changed[i]]+=1;
      }
      vector<int> ans;
      priority_queue<int,vector<int>,greater<int>> q(changed.begin(),changed.end());
      while(!q.empty())
      {
        int minimum=q.top();
        q.pop();
        if(s[minimum]!=0 && s[minimum*2]!=0)
        {
          ans.push_back(minimum);
          s[minimum*2]-=1;
          s[minimum]-=1;
        }
      }
      for(auto itr=s.begin();itr!=s.end();itr++)
      {
        if(itr->second!=0)
        {
          vector<int> temp;
          return temp;
        }
      }
      return ans;
    }
};

int main()
{
    vector<int> v={0,0,0,0};
    Solution s;
    vector<int> ans=s.findOriginalArray(v);
    for(auto i:ans)
      cout<<i<<" ";
    return 0;
}