class Solution {
public:
    bool solve(int s,int cur,int vis,int count,int target,vector<int> &nums){
        if((count) == 1) return true;
        if(cur>target) return false;
        if(cur==target){
            
            return solve(0,0,vis,count-1,target,nums);
        }
        for(int i=s;i<nums.size();i++){
            if(!(vis & 1<<i)){
                if(solve(i+1,cur+nums[i],(vis | 1<<i),count,target,nums)){
                    return true;
                }
                if(cur==0) return false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i:nums) sum+=i;
        sort(nums.begin(),nums.end(),std::greater<int>());
        if(sum%k!=0 || nums.size()<k) return false;
        return solve(0,0,0,k,sum/k,nums);
    }
};