class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mxp=1,mxn=1;
        int ans=INT_MIN;
        for(int i:nums){
            if(i==0){
                mxp=1;
                mxn=1;
                ans=max(ans,0);
            }
            else{
                if(i<0){
                int tmp=mxp;
                if(mxn!=1){
                    mxp=mxn*i;
                }else{
                    mxp=1;
                }
                mxn=mxp*i;
            }else{
                mxp*=i;
                if(mxn!=1){
                    mxn*=i;
                }
            }
            if(mxp!=1 || i==1)
            ans=max(ans,mxp);
            }
        }
        return ans;
    }
};
