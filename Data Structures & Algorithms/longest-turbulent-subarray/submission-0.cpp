class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=1,cur=1,sign=0,i=1;
        while(i<arr.size()){
            if(sign==0){
                if(arr[i]!=arr[i-1]){
                    cur++;
                }
            }else if(sign<0){
                if(arr[i]>arr[i-1]){
                    cur++;
                }else if(arr[i]!=arr[i-1]){
                    cur=2;
                }else{
                    cur=1;
                }
            }else{
                if(arr[i]<arr[i-1]){
                    cur++;
                }else if(arr[i]!=arr[i-1]){
                    cur=2;
                }else{
                    cur=1;
                }
            }
            ans=max(ans,cur);
            sign=arr[i]-arr[i-1];
            i++;
        }
        return ans;
    }
};