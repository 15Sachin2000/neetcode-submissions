class Solution {
public:
    int solve(int i,vector<int> &stones,int target,int sum,int total,vector<vector<int>> &dp){
        if(i==stones.size() || sum>=target){
            return abs(total-2*sum);
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=min(solve(i+1,stones,target,sum+stones[i],total,dp),solve(i+1,stones,target,sum,total,dp));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i:stones) sum+=i;
        vector<vector<int>> dp(stones.size(),vector<int>(sum,-1));
        return solve(0,stones,ceil((sum*1.0)/2.0),0,sum,dp);
    }
};