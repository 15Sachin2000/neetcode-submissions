class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,-1);
        for(int c:coins){
            if(c<=amount)
            dp[c]=1;
        }
        dp[0]=0;
        sort(coins.begin(),coins.end());
        for(int i=1;i<=amount;i++){
            if(dp[i]!=-1){
                continue;
            }
            dp[i]=INT_MAX;
            for(int j:coins){
                if(j>i) break;
                if(dp[i-j]!=-1){
                    dp[i]=min(1+dp[i-j],dp[i]);
                }
            }
            if(dp[i]==INT_MAX) dp[i]=-1;
        }
        // for(int i:dp){
        //     cout<<i<<" ";
        // }
        return dp[amount];
    }
};
