class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i:nums) sum+=i;
        if(sum<target) return 0;
        int s=0,i=0,ans=n;
        sum=0;
        while(i<n){
            sum+=nums[i];
            while(sum>=target){
                ans=min(ans,i-s+1);
                sum-=nums[s++];
            }
            i++;
        }
        return ans;
    }
};