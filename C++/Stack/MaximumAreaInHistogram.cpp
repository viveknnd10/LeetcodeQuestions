class Solution {
public:
    vector<int> NSR(vector<int> heights)
    {
        stack<pair<int,int>> s;
        vector<int> v(heights.size());
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!s.empty() && s.top().first>=heights[i])
                s.pop();
            if(s.empty())
                v[i]=heights.size();
            else
                v[i]=s.top().second;
            s.push({heights[i],i});
        }
        return v;
    }
    vector<int> NSL(vector<int> heights)
    {
        stack<pair<int,int>> s;
        vector<int> v(heights.size());
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() && s.top().first>=heights[i])
                s.pop();
            if(s.empty())
                v[i]=-1;
            else
                v[i]=s.top().second;
            s.push({heights[i],i});
        }
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right=NSR(heights);
        vector<int> left=NSL(heights);
        vector<int> width(heights.size());
        for(int i=0;i<heights.size();i++)
            width[i]=right[i]-left[i]-1;
        int maxVal=INT_MIN;
        for(int i=0;i<width.size();i++)
            maxVal=max(maxVal,width[i]*heights[i]);
        return maxVal;
        
    }
};