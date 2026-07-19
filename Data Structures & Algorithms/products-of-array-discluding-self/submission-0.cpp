class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n,1);
        vector<int> post(n,1);
        pre[0]=nums[0];
        post[n-1]=nums[n-1];
        for(int i=1;i<n-1;i++){
            pre[i]=nums[i]*pre[i-1];
        };
        for(int i=n-2;i>=0;i--){
            post[i]=nums[i]*post[i+1];
        }
        vector<int> ans(n,1);
        for(int i=0;i<n;i++){
            if(i!=0){
                ans[i]*=pre[i-1];
            }
            if(i!=n-1){
                ans[i]*=post[i+1];
            }
        };
        return ans;
    }
};
