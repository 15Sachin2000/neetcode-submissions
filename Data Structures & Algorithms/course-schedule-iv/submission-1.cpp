class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> inc(numCourses,0);
        for(vector<int> v:prerequisites){
            adj[v[0]].push_back(v[1]);
            inc[v[1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inc[i]==0) q.push(i);
        }
        vector<unordered_set<int>> pre(numCourses);
        while(!q.empty()){
            int k=q.front();
            cout<<k<<endl;
            q.pop();
            for(int i:adj[k]){
                pre[i].insert(k);
                pre[i].insert(pre[k].begin(),pre[k].end());
                if(--inc[i]==0) q.push(i); 
            }
        }
        vector<bool> ans;
        for(vector<int> v:queries){
            // ans.push_back(pre[v[1]].find(v[0])!=pre[v[1]].end());
            ans.push_back(pre[v[1]].contains(v[0]));
        }
        return ans;
    }
};