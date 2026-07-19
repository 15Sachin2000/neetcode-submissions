class Solution {
public:
    int solve(int i,string &s,vector<int> &dp){
        if(i==s.size()){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(s[i]=='0'){
            return 0;
        }
        if(i!=s.size()-1 && stoi(s.substr(i,2))<=26){
            return dp[i]=solve(i+1,s,dp)+solve(i+2,s,dp);
        }
        return dp[i]=solve(i+1,s,dp);
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,s,dp);
    }
};
