class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int rob1=0,rob2=0;
        if(n==1) return nums[0];
        for(int i=0;i<n-1;i++){
            int tmp=max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=tmp;
        }
        int ans1=rob2;
        rob1=0,rob2=0;
        for(int i=1;i<n;i++){
            int tmp=max(rob1+nums[i],rob2);
            rob1=rob2;
            rob2=tmp;
        }
        return max(ans1,rob2);
    }
};
