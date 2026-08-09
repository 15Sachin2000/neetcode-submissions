class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax=1,curMin=1,ans=INT_MIN;
        for(int i:nums){
            int tmp=i*curMax;
            curMax=max(max(tmp,curMin*i),i);
            curMin=min(min(tmp,curMin+i),i);
            ans=max(ans,curMax);
        }
        return ans;
    }
};
