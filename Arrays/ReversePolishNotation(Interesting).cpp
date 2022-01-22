class Solution {
public:
    int oper(int a, int b, string token){
        if(token == "+")
            return a + b;
        else if(token == "-")
            return a - b;
        else if(token == "*")
            return a * b;
        else
            return a / b;
    }
    bool isOperator(string token){
        return (token == "+") || (token == "-") || (token == "*") || (token == "/");
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> Stack;
        for(string token : tokens){
            if(isOperator(token)){
                int b = Stack.top();
                Stack.pop();
                int a = Stack.top();
                Stack.pop();
                int res = oper(a, b, token);
                Stack.push(res);
            }
            else{
                int num = stoi(token);
                Stack.push(num);
            }
        }
        return Stack.top();
    }
};