#include<bits/std++.h>
vector<string> dependencies(map<string,vector<string>> packageDependency,string target)
{
    queue<string> s;
    set<string> temp;
    s.push(target);
    while(!s.empty())
    {
        string temp1=s.front();
        s.pop();
        for(int i=0;i<packageDependency[temp1].size();i++)
        {
            s.push(temp1);
            temp.insert(temp1);
        }
        if(!packageDependency[temp1].size())
            break;
    }
    vector<string> ans;
    cout<<"debug";
    for(auto i=temp.begin();i!=temp.end();i++)
    {
        cout<<*i<<" ";
        if(*i==target)
            continue;
        else
            ans.push_back(*i);
    }
    
    return ans;
}
int main()
{
    map<string,vector<string>> input;
    vector<string> ans;
    input.insert({"packagea",{"packageb"}});
    input.insert({"packageb",{"packagec","packaged"}});
    input.insert({"packagec",{}});
    input.insert({"packaged",{"packagef","packager","packagep"}});
    input.insert({"packagef",{}});
    input.insert({"packager",{}});
    input.insert({"packagep",{}});
    ans=dependencies(input,"packagea");
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
}