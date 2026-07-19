class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,string w1, string w2){
        if(i==w1.size()){
            return w2.size()-j;
        }
        if(j==w2.size()){
            return w1.size()-i;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]){
            return dp[i][j]=solve(i+1,j+1,dp,w1,w2);
        }
        return dp[i][j]=1+min(solve(i+1,j,dp,w1,w2),min(solve(i,j+1,dp,w1,w2),solve(i+1,j+1,dp,w1,w2)));
    }
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(0,0,dp,word1,word2);
    }
};
