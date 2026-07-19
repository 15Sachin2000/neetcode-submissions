class Solution {
private:
    int solve(int b,int i,int flag,vector<vector<vector<int>>> &dp,vector<int>& prices){
        if(i>=prices.size()) return 0;
        if(dp[b][i][flag]!=-1) return dp[b][i][flag];
        int k=solve(b,i+1,flag,dp,prices);
        if(flag){
            if(prices[i]>b){
                dp[b][i][flag]=max(prices[i]-b+solve(0,i+2,0,dp,prices),k);
            }else{
                dp[b][i][flag]=k;
            }
        }else{
            dp[b][i][flag]=max(solve(prices[i],i+1,1,dp,prices),k);
        }
        return dp[b][i][flag];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(1001,vector<vector<int>>(n,vector<int>(2,-1)));
        return solve(0,0,0,dp,prices);
    }
};
