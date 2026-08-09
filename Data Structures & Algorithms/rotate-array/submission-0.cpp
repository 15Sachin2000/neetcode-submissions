class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        if(k==0) return;
        int i=0,j=n-k,p=n-k;
        while(i<k){
            swap(nums[i],nums[j]);
            i++;
            j++;
            if(j==n) j=p;
        }

    }
};