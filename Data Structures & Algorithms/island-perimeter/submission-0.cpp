class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int a[]={-1,0,1,0};
        int b[]={0,1,0,-1};
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int r=i+a[k],c=j+b[k];
                    if(r>=0 && r<n && c>=0 && c<m){
                        if(grid[r][c]==0) ans++;
                    }else{
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};