class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0,i=0,s=0;
        while(i<nums.size()){
            if(nums[i]!=val){
                swap(nums[i],nums[s]);
                s++;
                count++;
            }
            i++;
        }
        return count;
    }
};