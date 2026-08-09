class Solution {
public:
    int findIndex(vector<int> &nums){
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(mid>0 && nums[mid]<nums[mid-1]){
                return mid;
            }else if(nums[mid]>nums[r]){
                l=mid+1;
            }else if(nums[mid]<nums[r]){
                r=mid-1;
            }else{
                r--;
            }
        }
        return l;
    }
    bool search(vector<int>& nums, int target) {
        int idx=findIndex(nums),n=nums.size();
        cout<<idx<<endl;
        // return true;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            int i=(mid+idx)%n;
            if(nums[i]==target) return true;
            if(nums[i]>target){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
};