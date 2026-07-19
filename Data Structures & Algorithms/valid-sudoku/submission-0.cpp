class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> row(n,vector<bool>(9,false));
        vector<vector<bool>> col(m,vector<bool>(9,false));
        vector<vector<vector<bool>>> grid(n/3,vector<vector<bool>>(m/3,vector<bool>(9,0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=board[i][j]-'1';
                if(val>=0 && val<9){
                    if(row[i][val] || col[j][val] || grid[i/3][j/3][val]){
                        return false;
                    }
                    row[i][val]=true;
                    col[j][val]=true;
                    grid[i/3][j/3][val]=true;
                }
            }
        }
        return true;
    }
};
