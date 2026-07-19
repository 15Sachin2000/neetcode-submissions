class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),mp=0,mn=0,ans=nums[0];
        for(int i:nums){
            if(i==0){
                mp=0,mn=0;
            }
            if(i<0){
                int k=mn;
                if(!mp){
                    mn=i;
                }else{
                    mn=mp*i;
                }
                if(k){
                    mp=k*i;
                    ans=max(ans,mp);
                }else{
                    mp=0;
                }
                cout<<mp<<" "<<mn<<endl;
            }else{
                if(mp){
                    mp*=i;
                }else{
                    mp=i;
                }
                if(mn){
                    mn*=i;
                }
                cout<<mp<<" "<<mn<<endl;
                ans=max(ans,mp);
            }
        }
        return ans;
    }
};
