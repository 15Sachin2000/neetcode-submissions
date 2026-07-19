class Solution {
public:
    bool solve(int i,int j,int k,vector<vector<char>>& board, string &word,vector<vector<bool>> &vis){
        if(k==word.size()) return true;
        if(i<0 ||j<0 || i==board.size() || j==board[0].size()) return false;
        if(board[i][j]!=word[k] || vis[i][j]) return false;
        vis[i][j]=true;
        int row[4]={1,0,-1,0};
        int col[4]={0,-1,0,1};
        for(int a=0;a<4;a++){
            if(solve(i+row[a],j+col[a],k+1,board,word,vis))
                return true;
        }
        vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool res=solve(i,j,0,board,word,vis);
                if(res) return true;
            }
        }
        return false;
    }
};
