class Solution {
private:
    int solve(int i,int t,int f,vector<int> &nums,vector<vector<vector<int>>> &dp){
        cout<<f<<endl;
        if(i==nums.size()){
            if(t==0) return 1;
            return 0;
        }
        if(dp[i][t][f]!=-1){

            return dp[i][t][f];
        }
        int v=(f!=1)?-1*t:t;
        int a=v+nums[i];
        int b=v-nums[i];
        return dp[i][t][f]=solve(i+1,abs(a),a>=0,nums,dp)+solve(i+1,abs(b),b>=0,nums,dp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int mx=INT_MIN;
        for(int i:nums){
            mx=max(mx,abs(i));
        }
        int buffer=abs(target)+n*mx+1;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(buffer,vector<int>(2,-1)));
        return solve(0,abs(target),target>=0,nums,dp);
    }
};
