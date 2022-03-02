class Solution {
public:
    int longestPalindrome(string s) 
    {
      unordered_map<char,int> freq;
      int count=0;
      bool flag=false;
      for(auto i=0;i<s.size();i++)
      {
        freq[s[i]]++;
      }
      for(auto i=freq.begin();i!=freq.end();i++)
      {
        if(i->second%2==0)
          count+=i->second;
        else if(i->second%2!=0 && i->second>1)
        {
          count+=(i->second/2)*2;
          flag=true;
        }
        else
          flag=true;
      }
      if(flag)
        return count+1;
      return count;
    }
};