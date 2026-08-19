class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size(),c=heights[0].size();
        int a[]={-1,0,1,0};
        int b[]={0,1,0,-1};
        vector<vector<bool>> vis(r,vector<bool>(c,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,0,0});
        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
            if(vis[v[1]][v[2]]) continue;
            // cout<<v[1]<<" "<<v[2]<<" "<<v[0]<<endl;
            if(v[1]==r-1 && v[2]==c-1) return v[0];
            vis[v[1]][v[2]]=true;
            for(int i=0;i<4;i++){
                int x=v[1]+a[i],y=v[2]+b[i];
                if(x>=0 && x<r && y>=0 && y<c && !vis[x][y]){
                    pq.push({max(v[0],abs(heights[v[1]][v[2]]-heights[x][y])),x,y});
                }
            }
        }
        return -1;
    }
};