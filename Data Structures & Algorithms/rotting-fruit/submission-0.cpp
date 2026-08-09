class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=-1;
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                pair<int,int> p=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int a=p.first+dir[k][0];
                    int b=p.second+dir[k][1];
                    if(a>=0 && a<n && b>=0 && b<m && grid[a][b]==1){
                        grid[a][b]=2;
                        q.push({a,b});
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
