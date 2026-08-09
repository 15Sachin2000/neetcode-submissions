class Solution {
public:
    bool dfs(vector<vector<int>> &adj,int s,int d){
        if(s==d) return true;
        for(int i:adj[s]){
            if(dfs(adj,i,d)) return true;
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        for(vector<int> v:prerequisites){
            adj[v[0]].push_back(v[1]);
        }
        vector<bool> ans;
        for(vector<int> v:queries){
            if(dfs(adj,v[0],v[1])){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};