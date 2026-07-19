class Solution {
public:
    void solve(int idx,vector<int> &nums,int t,vector<int> &tmp,vector<vector<int>> &ans){
        if(t==0){
            ans.push_back(tmp);
            return;
        }
        if(idx>=nums.size() || t<0) return;
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            tmp.push_back(nums[i]);
            solve(i+1,nums,t-nums[i],tmp,ans);
            tmp.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        vector<int> tmp;
        vector<vector<int>> ans;
        solve(0,nums,t,tmp,ans);
        return ans;
    }
};
