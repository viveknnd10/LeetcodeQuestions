class Solution {
public:
    int findPivot(vector<int>& nums,int left,int right)
    {
      if(left>=right)
      {
        return -1;
      }
      int mid=(left+right)/2;
      if(nums[mid]>nums[mid+1])
      {
        return mid;
      }
      else
      {
        if(nums[mid]<nums[mid+1] && nums[right]>nums[mid])
          return findPivot(nums,left,mid);
        else
          return findPivot(nums,mid,right);
      }
      
    }
  int binarySearch(vector<int>& nums,int left,int right,int target)
  {
    int mid=(left+right)/2;
    cout<<mid<<endl;
    if(nums[mid]==target)
    {
      return mid;
    }
    if(left>=right)
    {
      return -1;
    }
    else
    {
      if(nums[mid]<target)
      {
        return binarySearch(nums,mid+1,right,target);
      }
      else
      {
        return binarySearch(nums,left,mid,target);
      }
    }
  }
    int search(vector<int>& nums, int target) 
    {
      int pivot=-1,left=0,right=nums.size()-1;
      if(nums.size()!=1)
        pivot=findPivot(nums,left,right);
      cout<<pivot<<endl;
      if(pivot==-1)
      {
        return binarySearch(nums,left,right,target);
      }
      else if(nums[pivot]<target)
      {
        return -1;
      }
      else if(nums[0]<=target)
      {
        return binarySearch(nums,left,pivot,target);
      }
      else
      {
        return binarySearch(nums,pivot+1,right,target);
      }
       return 0; 
    }
};