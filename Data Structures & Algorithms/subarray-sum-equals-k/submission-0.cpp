class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int l=0;i+l<nums.size();l++){
                sum+=nums[i+l];
                if(sum==k){
                    // cout<<i<<" "<<l<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};