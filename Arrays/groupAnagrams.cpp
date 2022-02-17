class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
      unordered_map<string,vector<string>> result;
      vector<vector<string>> final_result;
      for(int i=0;i<strs.size();i++)
      {
        vector<int> v(26,0);
        string temp;
        for(int j=0;j<strs[i].size();j++)
        {
          int t=strs[i][j]-'a';
          v[t]+=1;
        }
        for(int j=0;j<v.size();j++)
        {
          temp+=char(v[j]);
        }
        result[temp].push_back(strs[i]);
      }
      for(auto i=result.begin();i!=result.end();i++)
      {
        final_result.push_back(i->second);
      }
      return final_result;
    }
};