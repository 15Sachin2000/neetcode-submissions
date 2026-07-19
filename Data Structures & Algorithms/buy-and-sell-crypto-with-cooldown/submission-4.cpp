class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,n=prices.size();
        vector<int> dp(n,0);
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1];
            for(int j=0;j<i;j++){
                if(prices[i]>prices[j]){
                    int tmp=prices[i]-prices[j];
                    if(j-2>=0){
                        tmp+=dp[j-2];
                    }
                    dp[i]=max(dp[i],tmp);
                }
            }
            ans=max(ans,dp[i]);
        }
        return dp[n-1];
    }
};
