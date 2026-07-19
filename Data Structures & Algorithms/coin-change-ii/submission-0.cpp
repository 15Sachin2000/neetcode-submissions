class Solution {
private:
    int solve(int a,int i,vector<vector<int>> &dp,vector<int> &c){
        if(a==0) return 1;
        if(a<0 || i==c.size()) return 0;
        if(dp[a][i]!=-1) return dp[a][i];
        return dp[a][i]=solve(a,i+1,dp,c)+solve(a-c[i],i,dp,c);
    }
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(amount+1,vector<int>(n,-1));
        return solve(amount,0,dp,coins);
    }
};
