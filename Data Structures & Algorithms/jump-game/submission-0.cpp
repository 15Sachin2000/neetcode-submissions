class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size(), mxIdx=0,i=0;
        while(i<n){
            if(mxIdx<i){
                return false;
            }
            mxIdx=max(mxIdx,i+nums[i]);
            i++;
        }
        return true;
    }
};
