class Solution {
public:
    int solve(int s,int m,vector<int> &piles,vector<vector<int>> &dp,vector<int> &prefix){
        int n=piles.size();
        if(s>=n) return 0;
        if(dp[s][m]!=-1) return dp[s][m];
        int l=min(n-1,s+2*m-1),i=s,ans=0,sum=0;
        if(l==n-1) return dp[s][m]=prefix[s];
        while(i<=l){
            sum+=piles[i];
            i++;
            int nm=min(max(m,i-s),n);
            ans=max(ans,sum+prefix[i]-solve(i,nm,piles,dp,prefix));
        }
        return dp[s][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size(),sum=0;
        vector<int> prefix(n,0);
        for(int i=n-1;i>=0;i--){
            sum+=piles[i];
            prefix[i]=sum;
        }
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,1,piles,dp,prefix);
    }
};