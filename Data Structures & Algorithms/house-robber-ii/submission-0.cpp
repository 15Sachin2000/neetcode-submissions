class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int mx1=0,mx2=0;
        for(int i=0;i<n-1;i++){
            int k=nums[i]+mx1;
            mx1=mx2;
            mx2=max(mx2,k);
        }
        cout<<mx1<<". "<<mx2<<endl;
        int ans=mx2;
        mx1=0,mx2=0;
        for(int i=1;i<n;i++){
             int k=nums[i]+mx1;
             mx1=mx2;
             mx2=max(mx2,k);
        }
        cout<<mx1<<". "<<mx2<<endl;
        return max(ans,mx2);
    }
};
