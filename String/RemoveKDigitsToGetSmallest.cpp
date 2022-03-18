/*less efficient Solution*/
class Solution {
public:
    string desiredNumber(string num,int k,int count,int length)
    {
      if(length-count==num.size())
        return num;
      int no_dig=length-count;
      priority_queue<pair<char,int>,vector<pair<char,int>>,greater<pair<char,int>>> pq;
      for(int i=0;i<num.size();i++)
      {
        pq.push({num[i],i});
      }
      while(!pq.empty())
      {
        auto [nums,index]=pq.top();
        pq.pop();
        if(num.substr(index+1,num.size()).size()>=no_dig-1)
        {
          return nums+desiredNumber(num.substr(index+1,num.size()),k,count+1,length);
        }
      }
      return "";
    }
    string removeKdigits(string num, int k) 
    {
      if(k>=num.size())
        return "0";
      int count=0,length=num.size()-k;
      string st=desiredNumber(num,k,count,length);
      int left=0;
      while(st[left]=='0')
        left++;
      if(left==st.size())
        return "0";
      return st.substr(left,st.size());
    }
};

/*optimized Solution*/
class Solution {
public:
    string removeKdigits(string num, int k) 
    {
      if(k>=num.size())
        return "0";
      stack<char> st;
      for(char c:num)
      {
        while(st.size()>0 && k>0 && st.top()>c)
        {
          st.pop();
          k-=1;
        }
        st.push(c);
      }
      for(int i=0;i<k;i++)
      {
        st.pop();
      }
      string s="";
      while(!st.empty())
      {
        s+=st.top();
        st.pop();
      }
      reverse(s.begin(),s.end());
      int left=0;
      while(s[left]=='0')
        left++;
      if(left==s.size())
        return "0";
      return s.substr(left,s.size());
    }
};