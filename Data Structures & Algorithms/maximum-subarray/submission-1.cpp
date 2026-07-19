class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),ans=INT_MIN,mx=0;
        for(int num:nums){
            int k=mx+num;
            ans=max(ans,k);
            if(k>=0){
                mx=k;
            }else{
                mx=0;
            }
        }
        return ans;
    }
};
