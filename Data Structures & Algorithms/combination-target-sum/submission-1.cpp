class Solution {
public:
    void solve(int i,int sum,vector<int> &nums,int target,vector<vector<int>> &ans,vector<int> &tmp){
        if(sum==target){
            ans.push_back(tmp);
            return;
        }
        if(sum>target || i==nums.size()) return;
        tmp.push_back(nums[i]);
        solve(i,sum+nums[i],nums,target,ans,tmp);
        tmp.pop_back();
        solve(i+1,sum,nums,target,ans,tmp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0,0,nums,target,ans,tmp);
        return ans;       
    }
};
