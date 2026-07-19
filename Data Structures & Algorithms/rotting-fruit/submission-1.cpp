class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0,n=grid.size(),m=grid[0].size(),ans=0;
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fresh++;
                }else if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<int> r={-1,0,1,0};
        vector<int> c={0,1,0,-1};
        while(fresh && !q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                vector<int> tmp=q.front();
                q.pop();
                int x=tmp[0],y=tmp[1];
                for(int k=0;k<4;k++){
                    int x1=x+r[k],y1=y+c[k];
                    if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]==1){
                        q.push({x1,y1});
                        grid[x1][y1]=2;
                        fresh--;
                    }
                }
            }
            ans++;
        }
        if(fresh>0) return -1;
        return ans;
    }
};
