class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,s=0,i=0,n=nums.size(),ans=INT_MIN;
        while(i<n){
            sum+=nums[i];
            ans=max(ans,sum);
            while(sum<0){
                sum-=nums[s];
                s++;
            }
            i++;
        }
        return ans;
    }
};
