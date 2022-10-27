class Solution {
public:
    string decoded(string s,int &i)
    {
      string res;
      while(i<s.length() && s[i]!=']')
      {
        if(!isdigit(s[i]))
          res+=s[i++];
        else
        {
          int n=0;
          while(i<s.length() && isdigit(s[i]))
            n=(n*10)+(s[i++]-'0');
          i++;
          string t=decoded(s,i);
          i++;
          while(n>0)
          {
            res+=t;
            n--;
          }
        }
      }
      return res;
    }
    string decodeString(string s) 
    {
      int i=0;
      return decoded(s,i);
    }
};