class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) 
    {
      int shiftby=0;
      bool flag=false;
      for(auto i:shift)
      {
        if(i[0]==0)
          shiftby=shiftby-i[1];
        if(i[0]!=0)
          shiftby=shiftby+i[1];
      }
      flag=shiftby>0?1:0;
      shiftby=abs(shiftby);
      shiftby=shiftby%s.size();
      cout<<flag<<endl;
      if(flag)
        return s.substr(s.size()-shiftby,s.size())+s.substr(0,s.size()-shiftby); 
      return s.substr(shiftby,s.size())+s.substr(0,shiftby);
    }
};