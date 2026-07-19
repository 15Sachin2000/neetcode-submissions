class Solution {
private:
    int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dir){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int area=1;
        for(int k=0;k<4;k++){
            area+=solve(i+dir[k][0],j+dir[k][1],grid,dir);
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int k=solve(i,j,grid,dir);
                    ans=max(ans,k);
                }
            }
        }
        return ans;
    }
};
