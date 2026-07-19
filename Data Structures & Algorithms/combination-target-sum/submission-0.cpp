class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int> &nums,int target,vector<int> &tmp){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        if(target<0 || i>=nums.size()) return;
        tmp.push_back(nums[i]);
        solve(i,nums,target-nums[i],tmp);
        tmp.pop_back();
        solve(i+1,nums,target,tmp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> tmp;
        solve(0,nums,target,tmp);
        return ans;
    }
};
