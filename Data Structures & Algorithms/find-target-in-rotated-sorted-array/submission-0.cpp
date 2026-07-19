class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        int i=l,j=n-1+l;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid%n]==target){
                return mid%n;
            }else if(nums[mid%n]>target){
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return -1;
    }
};
