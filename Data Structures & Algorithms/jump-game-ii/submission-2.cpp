class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int ans=1,curmx=nums[0],mx=nums[0];
        for(int i=1;i<nums.size();i++){
            if(curmx<i){
                ans++;
                curmx=mx;
            }
            mx=max(mx,i+nums[i]);
        }
    return ans;
    }
};
