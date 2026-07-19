class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int k=nums[i]%(n+1);
            if(nums[k-1]/(n+1)){
                return k;
            }
            nums[k-1]+=n+1;
        }
        return -1;
    }
};
