class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        int n=nums.size();
        vector<int> dp(n+1,INT_MAX);
        for(auto itr:mp){
            dp[itr.second]=itr.first;
        };
        vector<int> ans;
        while(k>0 && n>0){
            if(dp[n]!=INT_MAX){
                ans.push_back(dp[n]);
                k--;
            }
            n--;
        };
        return ans;
    }
};
