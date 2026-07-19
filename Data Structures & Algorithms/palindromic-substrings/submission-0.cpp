class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=n;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            if(i!=n-1 && s[i]==s[i+1]){
                dp[i][i+1]=1;
                ans++;
            }
        }
        for(int l=3;l<=n;l++){
            for(int i=0;i+l<=n;i++){
                if(s[i]==s[i+l-1] && dp[i+1][i+l-2]){
                    dp[i][i+l-1]=1;
                    ans++;
                }
            }
        }
        return ans;
    }
};
