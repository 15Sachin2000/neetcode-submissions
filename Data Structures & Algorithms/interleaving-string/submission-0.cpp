class Solution {
private:
    int solve(int i1,int i2,int i3,vector<vector<vector<int>>> &dp,string &s1, string &s2, string &s3){
        if(i3==s3.size()) return 1;
        if(dp[i1][i2][i3]!=-1){
            cout<<"dp";
             return dp[i1][i2][i3];}
        int a=0,b=0;
        if(i1<s1.size() && s1[i1]==s3[i3]){
            a=solve(i1+1,i2,i3+1,dp,s1,s2,s3);
        }
        if(i2<s2.size() && s2[i2]==s3[i3]){
            b=solve(i1,i2+1,i3+1,dp,s1,s2,s3);
        }
        return dp[i1][i2][i3]=a||b;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.size(),l2=s2.size(),l3=s3.size();
        if(l3!=l1+l2) return 0;
        vector<vector<vector<int>>> dp(l1+1,vector<vector<int>>(l2+1,vector<int>(l3+1,-1)));
        return solve(0,0,0,dp,s1,s2,s3);
    }
};
