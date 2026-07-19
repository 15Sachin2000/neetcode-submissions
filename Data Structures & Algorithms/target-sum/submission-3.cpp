class Solution {
public:
    int solve(int i,int t,vector<int> &nums,vector<vector<int>> &dp){
        if(t==0 &&  i==nums.size()) return 1;
        if(t<0 || i>=nums.size()) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        return dp[i][t]=solve(i+1,t-nums[i],nums,dp)+solve(i+1,t,nums,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        int t=(target+sum)/2;
        if((target+sum)%2) return 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(t+1,-1));
        return solve(0,t,nums,dp);
    }
};
