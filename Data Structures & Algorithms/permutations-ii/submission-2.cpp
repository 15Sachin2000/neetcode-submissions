class Solution {
public:
    void solve(int i,vector<int> &nums,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j!=i && nums[j]==nums[i]){
                continue;
            }
            swap(nums[i],nums[j]);
            solve(i+1,nums,ans);
            
        }
        for(int j=nums.size()-1;j>i;--j){
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        solve(0,nums,ans);
        // for(int i=0;i<num.size();i++){
        //     for(int j=i;j<nums.size();j++){

        //     }
        // }
        return ans;
    }
};