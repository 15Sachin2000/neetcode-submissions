class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int mx1=nums[n-1],mx2=nums[n-2];
        for(int i=n-3;i>=0;i--){
            int k=max(mx1+nums[i],mx2);
            mx1=mx2;
            mx2=k;
        }
        return max(mx1,mx2);
    }
};
