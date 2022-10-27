class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) 
    {
      int hottest=0;
      vector<int> answers(t.size(),0);
      for(int i=t.size()-1;i>=0;i--)
      {
        if(t[i]>=hottest)
        {
          hottest=t[i];
          continue;
        }
        int no_day=1;
        while(t[i]>=t[i+no_day])
        {
          no_day+=answers[i+no_day];
        }
        answers[i]=no_day;
      }
      return answers;
    }
};