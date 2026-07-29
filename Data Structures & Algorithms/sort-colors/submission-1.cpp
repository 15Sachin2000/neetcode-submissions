class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int z=0,o=0,t=0;
        // for(int i:nums){
        //     if(i==0) z++;
        //     if(i==1) o++;
        //     if(i==2) t++;
        // }
        // // cout<<z<<" "<<o<<" "<<t<<endl;
        // int i=0;
        // while(z>0){
        //     nums[i]=0;
        //     i++;
        //     z--;
        // }
        // while(o>0){
        //     nums[i]=1;
        //     i++;
        //     o--;
        // }
        // while(t>0){
        //     nums[i]=2;
        //     i++;
        //     t--;
        // }
        int l=0,r=nums.size()-1,i=0;
        while(i<=r){
            if(nums[i]==0){
                swap(nums[i],nums[l]);
                i++;
                l++;
            }else if(nums[i]==2){
                swap(nums[r],nums[i]);
                r--;
            }else{
                i++;
            }
        }
    }
};