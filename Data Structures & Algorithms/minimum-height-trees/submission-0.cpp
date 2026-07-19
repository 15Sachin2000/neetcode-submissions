class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> inc(n,0);
        for(vector<int> v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            inc[v[0]]++;
            inc[v[1]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(inc[i]==1){
                q.push(i);
            }
        }
        int count=n;
        while(true){
            int sze=q.size();
            if(count<=2){
                break;
            }
            for(int e=0;e<sze;e++){
                int k=q.front();
                q.pop();
                count--;
                for(int i:adj[k]){
                    inc[i]--;
                    if(inc[i]==1){
                        q.push(i);
                    }
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};