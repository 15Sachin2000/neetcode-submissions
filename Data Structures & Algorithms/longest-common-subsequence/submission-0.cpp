class Solution {
private:
    int solve(int x,int y,vector<vector<int>> &dp,string &s1,string &s2){
        if(x<0 || y<0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        if(s1[x]==s2[y]) return dp[x][y]=1+solve(x-1,y-1,dp,s1,s2);
        return dp[x][y]=max(solve(x-1,y,dp,s1,s2),solve(x,y-1,dp,s1,s2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,dp,text1,text2);
    }
};
