class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(),mn=prices[0],ans=0;
        for(int i:prices){
            if(i>mn){
                ans=max(ans,i-mn);
            }else{
                mn=i;
            }
        }
        return ans;
    }
};
