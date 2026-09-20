class Solution {
    vector<vector<int>> res;
    vector<bool> visit;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        visit.assign(nums.size(), false);
        vector<int> perm;
        sort(nums.begin(), nums.end());
        dfs(nums, perm);
        return res;
    }

    void dfs(vector<int>& nums, vector<int>& perm) {
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]))
                continue;

            visit[i] = true;
            perm.push_back(nums[i]);
            dfs(nums, perm);
            visit[i] = false;
            perm.pop_back();
        }
    }
};