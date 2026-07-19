class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),sum=0,ans=0,curr=0;
        for(int i=0;i<n;i++){
            int k=gas[i]-cost[i];
            sum+=k;
            curr+=k;
            if(curr<0){
                curr=0;
                ans=i+1;
            }
        }
        if(sum<0) return -1;
        return ans;

    }
};
