class Solution {
public:
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     if(n==1) return nums[0];
    //     int mx1=nums[n-1],mx2=nums[n-2];
    //     for(int i=n-3;i>=0;i--){
    //         int k=max(mx1+nums[i],max(mx2,mx1));
    //         mx1=mx2;
    //         mx2=k;
    //     }
    //     return max(mx1,mx2);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        if(n==1){
            return ans;
        }
        int rob1=nums[0],rob2=max(nums[0],nums[1]);
        ans=rob2;
        for(int i=2;i<n;i++){
            int tmp=max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=tmp;
            ans=max(ans,tmp);
        }
        return ans;
    }
};
