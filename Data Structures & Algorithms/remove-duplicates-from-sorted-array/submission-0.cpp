class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0,i=0,n=nums.size(),s=0;
        while(i<n){
            while(i+1<n && nums[i]==nums[i+1]){
                ans++;
                i++;
            }
            swap(nums[i],nums[s]);
            s++;
            i++;
        }
        return n-ans;
    }
};