class Solution {
public:
    bool solve(int i,int j,int k,vector<vector<char>> &b,string &w,vector<vector<bool>> &vis){
        if(k==w.size()){
            return true;
        };
        int n=b.size(),m=b[0].size();
        if(i>=n || j>=m || i<0 || j<0 || vis[i][j] || b[i][j]!=w[k]) return false;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        vis[i][j]=true;
        for(int a=0;a<4;a++){
            
                if(solve(i+r[a],j+c[a],k+1,b,w,vis)){
                    vis[i][j]=false;
                    return true;
                }
        }
        vis[i][j]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(i,j,0,board,word,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
