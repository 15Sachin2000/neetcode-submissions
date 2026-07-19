class Solution {
public:
    int jump(vector<int>& nums) {
        int mx=0,curr=0,i=0,ans=0;
        while(i<nums.size()){
            if(curr<i){
                ans++;
                curr=mx;
            }
            mx=max(mx,i+nums[i]);
            i++;
        }
        return ans;
    }
};
