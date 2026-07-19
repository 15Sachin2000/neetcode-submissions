class Solution {
public:
    int integerBreak(int n) {
        if(n<=3) return n-1;
        vector<int> dp(n+1);
        // dp[]
        for(int i=4;i<=n;i++){
            dp[i]=INT_MIN;
            for(int j=2;j<=i/2;j++){
                int a=j,b=i-j;
                int mx=1;
                if(a<=3){
                    mx*=a;
                }else{
                    mx*=dp[a];
                }
                if(b<=3){
                    mx*=b;
                }else{
                    mx*=dp[b];
                }
                dp[i]=max(dp[i],mx);
            }
        }
        for(int i:dp){
            cout<<i<<" ";
        }
        return dp[n];
    }
};