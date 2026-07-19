class Solution {
public:
    int solve(int i,int sum,vector<int> &nums,vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(i==nums.size() || sum<0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int a=solve(i+1,sum,nums,dp);
        int b=solve(i+1,sum-nums[i],nums,dp);
        cout<<a<<" "<<b<<endl;
        if(a || b){
            dp[i][sum]=1;
        }else{
            dp[i][sum]=0;
        }
        return dp[i][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        int k=solve(0,sum/2,nums,dp);
        cout<<k<<endl;
        if(k) return true;
        return false;
    }
};
