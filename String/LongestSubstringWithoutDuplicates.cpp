int lengthOfLongestSubstring(string s) 
    {
        int left=0,right=0,maxValue=0,count=0;
        vector<int> bitmap(256,0);
        while(right<s.size())
        {
            if(bitmap[s[right]]==0)
            {
                count++;
                bitmap[s[right]]+=1;
                right++;
            }
            else
            {
                count--;
                bitmap[s[left]]-=1;
                left++;
            }
            maxValue=max(maxValue,count);
        }
        return maxValue;
        
    }