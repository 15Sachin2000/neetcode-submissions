class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,p=prices[0],i=1,n=prices.size();
        while(i<n){
            if(prices[i]>p){
                ans+=prices[i]-p;
            }
            p=prices[i];
            i++;
        }
        return ans;
    }
};