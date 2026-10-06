class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0;
        while(i<n){
            if(mp[nums[i]]>0) return true;
            mp[nums[i]]=1;
            if(i-k>=0) mp[nums[i-k]]--;
            i++;
        }
        return false;
    }
};