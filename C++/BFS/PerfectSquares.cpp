class Solution {
public:
    int numSquares(int n) 
    {
      vector<int> squares;
      for(int i=1;i<=sqrt(n);i++)
      {
        squares.push_back(i*i);
      }
      queue<int> level;
      level.push(n);
      int count=0;
      while(!level.empty())
      {
        unordered_set<int> s;
        int qsize=level.size();
        for(int i=0;i<qsize;i++)
        {
          int frontvalue=level.front();
          if(frontvalue==0)
            {
              return count;
            }
          for(int j=0;j<squares.size();j++)
          {
            if(frontvalue<squares[j])
            {
              break;
            }
              s.insert(frontvalue-squares[j]);
          }
          for(auto i=s.begin();i!=s.end();i++)
          {
            level.push(*i);
          }
          level.pop();
        }
        count++;
      }
      return 1;
    }
};