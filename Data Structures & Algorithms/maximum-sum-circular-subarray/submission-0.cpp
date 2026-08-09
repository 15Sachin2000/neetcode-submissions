class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0,mn=0,total=0;
        for(int i:nums){
            sum+=i;
            if(sum>=0){
                sum=0;
            }
            mn=min(mn,sum);
            total+=i;
        }
        // cout<<mn<<" "<<total;
        return total-mn;
    }
};