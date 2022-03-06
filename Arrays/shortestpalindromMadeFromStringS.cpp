/* ques>You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"*/



class Solution {
public:
  vector<int> longestPrefixSuffix(string s)
  {
    int n=s.size();
    vector<int> lps(n,0);
    int i=1,j=0;
    while(i<n)
    {
      if(s[i]==s[j])
      {
        lps[i]=j+1;
        j++;
        i++;
      }
      else
      {
        if(s[i]!=s[j] && j!=0)
        {
          j=lps[j-1];
        }
        else
        {
          i++;
        }
      }
    }
    cout<<"debug"<<endl;
    return lps;
  }
    string shortestPalindrome(string s) 
    {
      if(s=="")
        return s;
      int n=s.size(),i;
      string temp=s;
      reverse(temp.begin(),temp.end());
      string temp2=s+'#'+temp;
      int n_new=temp2.size();
      cout<<"debug1"<<endl;
      vector<int> lps;
      lps=longestPrefixSuffix(temp2);
      if(i==n && s[0]==s[i-1])
        return s;
      return temp.substr(0,n-lps[n_new-1])+s;
      
    }
};