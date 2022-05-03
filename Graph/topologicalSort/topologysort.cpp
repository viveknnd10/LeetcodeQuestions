class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        int count=0;
        vector<int> answer;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                cout<<i<<endl;
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            answer.push_back(current);
            count++;
            for(auto it:adj[current])
                if(--indegree[it]==0)
                    q.push(it);
        }
        return count==numCourses?answer:vector<int>();
    }
};