class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<pair<int,int>> dp;
        for(auto itr:mp){
            dp.push_back({itr.second,itr.first});
        }
        sort(dp.begin(),dp.end());
        for(auto itr:dp){
            cout<<itr.first<<" "<<itr.second<<endl;
        }
        int n=dp.size();
        vector<int> ans;
        for(int i=n-1;i>=n-k;i--){
            ans.push_back(dp[i].second);
        }
        return ans;
    }
};
