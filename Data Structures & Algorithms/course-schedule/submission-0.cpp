class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> inc(n,0);
        vector<vector<int>> adj(n);
        for(vector<int> v:pre){
            inc[v[0]]++;
            adj[v[1]].push_back(v[0]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(inc[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int k=q.front();
            q.pop();
            for(int i:adj[k]){
                inc[i]--;
                if(inc[i]==0){
                    q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(inc[i]){
                return false;
            }
        }
        return true;
    }
};
