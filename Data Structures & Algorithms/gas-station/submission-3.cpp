class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=gas[i]-cost[i];
        }
        if(sum<0) return -1;
        int ans=0,j=0,tmp=0;
        while(j<n){
            if(tmp+gas[j]-cost[j]<0){
                ans=j+1;
                tmp=0;
            }else{
                tmp+=gas[j]-cost[j];
            }
            j++;
        }
        return ans;
    }
};
