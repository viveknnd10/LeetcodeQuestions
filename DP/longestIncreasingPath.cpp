class Solution {
public:
    int maxCount=1;
    vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    int DFS(vector<vector<int>>& matrix,int startX,int startY,vector<vector<int>> &dp)
    {
        if(dp[startX][startY]!=0)
            return dp[startX][startY];
        for(auto [x,y]:directions)
        {
            int newX=startX+x,newY=startY+y;
            if(newX<0||newY<0||newX>=matrix.size()||newY>=matrix[0].size())
                continue;
            if(matrix[newX][newY]>matrix[startX][startY])
            {
                dp[startX][startY]=max(dp[startX][startY],DFS(matrix,newX,newY,dp)+1);
                maxCount=max(maxCount,dp[startX][startY]);
            }
            else
            {
                if(dp[startX][startY]==0)
                    dp[startX][startY]=1;
            }
        }
        return dp[startX][startY];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        vector<vector<int>> dp(matrix.size(),(vector<int> (matrix[0].size(),0)));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                DFS(matrix,i,j,dp);
            }
        }
        return maxCount;
        
    }
};