class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int str=0,len=1;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            if(i!=n-1 && s[i]==s[i+1]){
                str=i;
                len=2;
                dp[i][i+1]=true;
            }
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                if(s[i]==s[i+l-1] && dp[i+1][i+l-2]){
                    dp[i][i+l-1]=true;
                    str=i;
                    len=l;
                }
            }
        }
        return s.substr(str,len);
    }
};
