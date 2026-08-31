class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int l=0,s=cost[n-1],i=n-2;
        while(i>=0){
            int tmp=min(l,s);
            l=s;
            s=cost[i]+tmp;
            i--;
        }
        return min(l,s);
    }
};
