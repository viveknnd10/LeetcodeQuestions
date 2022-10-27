class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
      int maxProfit=0,left=prices.size()-1,right=prices.size()-1;
      while(left>=0)
      {
        if(prices[right]-prices[left]>0)
        {
          if(prices[right]-prices[left]>maxProfit)
          {
            maxProfit=prices[right]-prices[left];
          }
        }
        else
        {
          right=left;
        }
        left--;
      }
      return maxProfit;
        
    }
};