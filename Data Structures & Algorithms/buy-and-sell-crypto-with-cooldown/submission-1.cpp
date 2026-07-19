class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n,0);
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(prices[i]>prices[j]){
                    int k=prices[i]-prices[j];
                    if(j>=2) k+=dp[j-2];
                    dp[i]=max(dp[i],k);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
