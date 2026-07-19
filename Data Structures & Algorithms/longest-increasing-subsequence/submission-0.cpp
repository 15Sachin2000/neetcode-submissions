class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            // cout<<dp[i]<<" ";
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
