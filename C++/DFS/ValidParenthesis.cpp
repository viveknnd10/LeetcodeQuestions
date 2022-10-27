class Solution {
public:
    bool isValid(string s) {
        if(s.empty()==1)
        {
            return 1;
        }
        stack<char> checker;
        checker.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]==')' || s[i]=='}' || s[i]==']')
            {
                if(checker.empty()==1)
                {
                    return 0;
                }
                else if((checker.top()=='(' && s[i]==')') || (checker.top()=='{' && s[i]=='}') || (checker.top()=='[' && s[i]==']'))
                {
                    checker.pop();
                }
                else
                {
                    break;
                }
            }
            else
            {
                checker.push(s[i]);
            }
        }
        if(checker.empty()==1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
};