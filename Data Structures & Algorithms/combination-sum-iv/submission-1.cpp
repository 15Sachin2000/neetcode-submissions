class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i:nums){
            if(i<=target)
            dp[i]=1;
        }
        for(int i=2;i<=target;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]+=dp[j]*dp[i-j];
            }
        }
        return dp[target];

    }
};