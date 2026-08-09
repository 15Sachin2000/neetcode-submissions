class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,n=nums.size()-1;
        for(int i:nums) sum+=i;
        if(sum<target) return 0;
        int i=0,j=n-1,ans=n;
        while(i<=j && sum>=target){
            ans=j-i+1;
            if(nums[i]>=nums[j]){
                sum-=nums[j--];
            }else{
                sum-=nums[i++];
            }
        }
        return ans;
    }
};