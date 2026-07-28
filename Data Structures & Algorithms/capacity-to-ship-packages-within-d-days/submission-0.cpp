class Solution {
public:
    bool solve(int w,vector<int> &arr,int d){
        int count=0,tmp=0;
        for(int i:arr){
            tmp+=i;
            if(tmp>w){
                count++;
                tmp=i;
            }
        }
        return count+1<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=weights[0],e=0;
        for(int i:weights){
            s=max(s,i);
            e+=i;
        }
        int ans=e;
        while(s<=e){
            int mid=(s+e)/2;
            if(solve(mid,weights,days)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
        return ans;
    }
};