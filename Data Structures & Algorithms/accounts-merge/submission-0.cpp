class Solution {
public:
    void solve(string str,unordered_map<string,vector<string>> &mp,vector<string> &tmp,unordered_set<string> &s){
        s.insert(str);
        tmp.push_back(str);
        for(string q:mp[str]){
            if(s.find(q)==s.end()){
                solve(q,mp,tmp,s);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> mp;
        for(vector<string> v:accounts){
            for(int i=1;i<v.size()-1;i++){
                for(int j=i+1;j<v.size();j++){
                    mp[v[i]].push_back(v[j]);
                    mp[v[j]].push_back(v[i]);
                }
            }
        }
        vector<vector<string>> ans;
        unordered_set<string> s;
        for(vector<string> v:accounts){
            if(s.find(v[1])==s.end()){
                vector<string> tmp;
                tmp.push_back(v[0]);
                solve(v[1],mp,tmp,s);
                sort(tmp.begin()+1,tmp.end());
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};