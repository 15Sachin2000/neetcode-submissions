class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &path,vector<vector<int>> &dp){
        int n=path.size(),m=path[0].size();
        if(i==n || j==m) return 0;
        if(path[i][j]) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=solve(i+1,j,path,dp)+solve(i,j+1,path,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o.size(),m=o[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,o,dp);
    }
};