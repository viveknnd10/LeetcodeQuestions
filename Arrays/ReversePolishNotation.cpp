class Solution {
public:
  int performOperation(int vala,int valb,char v)
  {
    if(v=='*')
      return vala*valb;
    else if(v=='+')
      return valb+vala;
    else if(v=='-')
      return valb-vala;
    else
      return valb/vala;
  }
    int evalRPN(vector<string>& tokens) 
    {
      stack<int> s;
      vector<string> v={"*","/","+","-"};
      for(int i=0;i<tokens.size();i++)
      {
        bool flag=false;
        if(find(v.begin(),v.end(),tokens[i])!=v.end())
        {
          flag=true;
        }
        if(flag==true)
        {
          int temp1=s.top(),temp2=0;
          s.pop();
          temp2=s.top();
          s.pop();
          s.push(performOperation(temp1,temp2,tokens[i][0]));
        }
        else
        {
          s.push(atoi(tokens[i].c_str()));
        }
      }
        return s.top();
    }
};