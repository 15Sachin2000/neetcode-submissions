class Solution {
public:
    string arrToString(vector<int>& v){
        string s="0000";
        for(int i=0;i<v.size();i++){
            s[i]+=v[i];
        }
        return s;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> s;
        for(string str:deadends) s.insert(str);
        if(s.find(target)!=s.end() || s.find("0000")!=s.end()) return -1;
        queue<pair<vector<int>,int>>q;
        q.push({{0,0,0,0},0});
        while(!q.empty()){
            vector<int> v=q.front().first;
            int ct=q.front().second;
            // cout<<ct<<endl;
            q.pop();
            string str=arrToString(v);
            // cout<<str<<" ";
            if(str==target) return ct;
            for(int i=0;i<4;i++){
                int a=v[i];
                v[i]=(a+1)%10;
                string g=arrToString(v);
                if(s.find(g)==s.end()){
                    q.push({v,ct+1});
                    s.insert(g);
                }
                v[i]=((a+9)%10); 
                g=arrToString(v);
                if(s.find(g)==s.end()){
                    q.push({v,ct+1});
                    s.insert(g);
                }
                v[i]=a;
            }

        }
        return -1;
    }
};