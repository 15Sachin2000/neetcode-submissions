class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int row[]={-1,0,1,0};
        int col[]={0,1,0,-1};
        int n=h.size(),m=h[0].size();
        vector<vector<vector<bool>>> vis(n,vector<vector<bool>>(m,vector<bool>(2,false)));
        queue<pair<int,int>> p;
        queue<pair<int,int>> a;
        for(int i=0;i<n;i++){
            vis[i][0][0]=true;
            p.push({i,0});
            vis[i][m-1][1]=true;
            a.push({i,m-1});
        }
        for(int i=0;i<m;i++){
            vis[0][i][0]=true;
            if(i!=0){
                p.push({0,i});
            }
            vis[n-1][i][1]=true;
            if(i!=m-1){
                a.push({n-1,i});
            }
        }
        while(!p.empty()){
            pair<int,int> tmp=p.front();
            p.pop();
            for(int i=0;i<4;i++){
                int q=tmp.first+row[i],w=tmp.second+col[i];
                if(q>=0 && q<n && w>=0 && w<m && h[q][w]>=h[tmp.first][tmp.second] && !vis[q][w][0]){
                    p.push({q,w});
                    vis[q][w][0]=true;
                }
            }
        }
        while(!a.empty()){
            pair<int,int> tmp=a.front();
            a.pop();
            for(int i=0;i<4;i++){
                int q=tmp.first+row[i],w=tmp.second+col[i];
                if(q>=0 && q<n && w>=0 && w<m && h[q][w]>=h[tmp.first][tmp.second] && !vis[q][w][1]){
                    a.push({q,w});
                    vis[q][w][1]=true;
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j][0] && vis[i][j][1]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
