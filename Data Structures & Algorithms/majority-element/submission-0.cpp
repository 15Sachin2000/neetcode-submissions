class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i=1,n=nums.size(),m=nums[0],c=1;
        while(i<n){
            if(nums[i]==m) c++;
            else c--;
            if(c==0){
                m=nums[i];
                c=1;
            }
            i++;
        }
        return m;
    }
};