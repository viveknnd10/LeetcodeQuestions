class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) 
    {
        if(k==0)
        {
            return 0;
        }
        vector<int> bitmap(256,0);
        int left=0,right=0,count=0,uniq=0,maxCount=0;
        while(right<s.size())
        {
            if(bitmap[s[right]]==0 && uniq<k)
            {
                bitmap[s[right]]+=1;
                right++;
                uniq++;
                count++;
            }
            else if(bitmap[s[right]]==0 && uniq>=k)
            {
                if(bitmap[s[left]]<=1)
                    uniq--;
                bitmap[s[left]]-=1;
                left++;
                count--;
            }
            else
            {
                bitmap[s[right]]+=1;
                right++;
                count++;
            }
            maxCount=max(count,maxCount);
        }
        return maxCount;
        
    }
};