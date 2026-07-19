class Solution {
private:
    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &dir){
        if(i<0 ||i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        for(int k=0;k<4;k++){
            dfs(i+dir[k][0],j+dir[k][1],grid,dir);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    // cout<<i<<" "<<j<<endl;
                    dfs(i,j,grid,dir);
                    ans++;
                }
            }
        }
        // for(vector<char> v:grid){
        //     for(char c:v){
        //         cout<<c<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    }
};
