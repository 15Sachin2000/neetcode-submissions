class Solution {
public:
    bool solve(int i,int j,string &s1,string &s2,string &s3,vector<vector<int>> &dp){
        if(i==s1.size() && j==s2.size()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool b=false;
        if(i<s1.size() && s1[i]==s3[i+j]){
            if(solve(i+1,j,s1,s2,s3,dp)){
                return dp[i][j]=1;
            }
        }
        if(j<s2.size() && s2[j]==s3[i+j]){
            if(solve(i,j+1,s1,s2,s3,dp)){
                return dp[i][j]=1;
            }
        }
        return dp[i][j]=0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size(),n2=s2.size(),n3=s3.size();
        if(n1+n2!=n3) return false;
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};
