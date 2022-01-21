class Solution {
public:
    int openLock(vector<string>& deadends, string target) 
    {
      unordered_set<string> block;
      for(int i=0;i<deadends.size();i++)
      {
        block.insert(deadends[i]);
      }
      if(block.find("0000")!=block.end())
      {
        return -1;
      }
      queue<pair<string,int>> q;
      q.push({"0000",0});
      block.insert("0000");
      while(!q.empty())
      {
        auto [temp,count]=q.front();
        q.pop();
        if(temp==target)
        {
          return count;
        }
        for(int i=0;i<4;i++)
        {
          for(int j=-1;j<=1;j+=2)
          {
            string str=temp.substr(0,i)+to_string((temp.at(i)-'0'+j+10)%10)+temp.substr(i+1,temp.size());
            if(block.find(str)==block.end())
            {
              q.push({str,count+1});
              block.insert(str);
            }
          }
        }
      }
      return -1;
    }
};