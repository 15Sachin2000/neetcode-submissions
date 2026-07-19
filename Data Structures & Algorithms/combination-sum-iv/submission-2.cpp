class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1,0);
        dp[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<=target;i++){
            for(int j:nums){
                if(j>i) break;
                dp[i]+=dp[i-j];
            }
        }
        return dp[target];

    }
};