class Solution {
private:
    double bfs(string i,string f,unordered_map<string,vector<pair<string,double>>> &adj){
        if(adj.find(i)==adj.end()) return -1;
        queue<pair<string,double>> q;
        unordered_set<string> s;
        q.push({i,1});
        s.insert(i);
        while(!q.empty()){
            string str=q.front().first;
            double val=q.front().second;
            q.pop();
            if(str==f) return val;
            for(pair<string,double> pr:adj[str]){
                if(s.find(pr.first)==s.end()){
                    s.insert(pr.first);
                    q.push({pr.first,pr.second*val});
                }
            }
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        int n=values.size();
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> ans;
        for(vector<string> v:queries){
            ans.push_back(bfs(v[0],v[1],adj));
        }
        return ans;
    }
};