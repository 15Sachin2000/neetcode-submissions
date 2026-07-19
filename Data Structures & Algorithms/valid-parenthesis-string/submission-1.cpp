class Solution {
public:
    bool solve(int i,string &s,int c,vector<vector<int>> &dp){
        if(c<0) return false;
        if(i==s.size()){
            if(c==0) return true;
            return false;
        }
        if(dp[i][c]!=-1){
            return dp[i][c];
        }
        if(s[i]=='('){
            return dp[i][c]=solve(i+1,s,c+1,dp);
        }else if(s[i]==')'){
            return dp[i][c]=solve(i+1,s,c-1,dp);
        }
        return dp[i][c]=solve(i+1,s,c+1,dp) || solve(i+1,s,c,dp) || solve(i+1,s,c-1,dp);
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,s,0,dp);
    }
};
