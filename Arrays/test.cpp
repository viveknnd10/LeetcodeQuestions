vector<string> getItems(vector<vector<string>> entries) 
{
    vector<string> ans;
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
    int k=0;
    for(auto edge:entries)
    {
        if(edge[0]=="INSERT")
        {
            pq.push({stoi(edge[2]),edge[1]});
        }
        else if(edge[0]=="VIEW")
        {
            string namemain="";
            stack<pair<int,string>> s;
            for(int i=0;i<=k;i++)
            {
                auto [value,name]=pq.top();
                s.push({value,name});
                namemain=name;
                pq.pop();
            }
            ans.push_back(namemain);
            while(!s.empty())
            {
                pq.push(s.top());
                s.pop();
            }
            k++;
        }
    }
    return ans;
}