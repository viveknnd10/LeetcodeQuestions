class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
      unordered_set<string> list(wordList.begin(),wordList.end());
      unordered_map<string,int> distance;
      for(auto i=list.begin();i!=list.end();i++)
      {
        distance[*i]=INT_MAX;
      }
      queue<string> q;
      q.push(beginWord);
      distance[beginWord]=0;
      while(!q.empty())
      {
        string temp=q.front();
        q.pop();
        for(int i=0;i<temp.size();i++)
        {
          for(char j='a';j<='z';j++)
          {
            string str=temp;
            str[i]=j;
            if(list.find(str)!=list.end() && distance[str]==INT_MAX)
            {
              q.push(str);
              distance[str]=distance[temp]+1;
              if(str==endWord)
              {
                return distance[str]+1;
              }
            }
          }
        }
      }
      return 0;
    }
};