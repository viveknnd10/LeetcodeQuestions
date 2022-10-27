#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) 
    {
      int n=height.size()-1,ans=0,left=0,right=n,mxL=0,mxR=0;
      while(left<=right)
      {
        if(mxL<mxR)
        {
          ans+=max(0,mxL-height[left]);
          mxL=max(mxL,height[left]);
          left++;
        }
        else
        {
          ans+=max(0,mxR-height[right]);
          mxR=max(mxR,height[right]);
          right--;
        }
      }
      return ans;
    }
};

int main()
{
    Solution s;
    vector<int> v={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<s.trap(v)<<endl;
    return 0;
}