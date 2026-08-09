class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0,mn=0,total=0,mx=nums[0],mxSum=0;
        for(int i:nums){
            sum+=i;
            mxSum+=i;
            mn=min(mn,sum);
            mx=max(mx,mxSum);
            if(sum>=0){
                sum=0;
            }else{
                mxSum=0;
            }
            total+=i;
        }
        // cout<<mn<<" "<<total;
        return max(mxSum,total-mn);
    }
};