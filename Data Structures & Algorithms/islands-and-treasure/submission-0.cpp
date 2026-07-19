class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf=INT_MAX,n=grid.size(),m=grid[0].size();
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }
        while(!q.empty()){
            vector<int> v=q.front();
            q.pop();
            int i=v[0],j=v[1],l=v[2];
            for(int k=0;k<4;k++){
                int a=i+dir[k][0],b=j+dir[k][1];
                if(a>=0 && a<n && b>=0 && b<m && grid[a][b]==inf){
                    grid[a][b]=l+1;
                    q.push({a,b,l+1});
                }
            }
        }
    }
};
