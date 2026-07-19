class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=1;
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
                vis[n-1][i]=1;
            }
        }
        for(int i=1;i<n-1;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=1;
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                vis[i][m-1]=1;
            }
        }
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            for(int i=0;i<4;i++){
            int x=p.first+r[i], y=p.second+c[i];
                if(x>=0 && x<n && y>=0 && y<m && board[x][y]=='O' && !vis[x][y]){
                    q.push({x,y});
                    vis[x][y]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};
