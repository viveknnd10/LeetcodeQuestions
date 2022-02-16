class Solution {
public:
    int firstUniqChar(string s) 
    {
      unordered_map<char,int> temp;
      vector<char> v;
      for(int i=0;i<s.size();i++)
      {
        char x=s.at(i);
        if(temp.find(x)!=temp.end())
        {
          auto temp1=temp.find(x);
          temp1->second+=1;
        }
        else
        {
          temp.insert({x,1});
        }
      }
      for(auto r=temp.begin();r!=temp.end();r++)
      {
        if(r->second==1)
        {
          v.push_back(r->first);
        }
      }
      for(int i=0;i<s.size();i++)
      {
        
        for(auto f:v)
        {
          if(f==s.at(i))
            return i;
        }
      }
      return -1;
        
    }
};