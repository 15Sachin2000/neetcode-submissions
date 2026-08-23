class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        priority_queue<pair<int,char>> pq;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            pq.push({itr->second,itr->first});
        }
        string ans="";
        while(!pq.empty()){
            char c1=pq.top().second;
            int n1=pq.top().first;
            pq.pop();
            if(pq.empty()){
                if(n1>=2) return "";
                ans.push_back(c1);
                break;
            }
            char c2=pq.top().second;
            int n2=pq.top().first;
            pq.pop();
            ans.push_back(c1);
            ans.push_back(c2);
            if(--n1>0){
                pq.push({n1,c1});
            }
            if(--n2>0){
                pq.push({n2,c2});
            }
        }
        return ans;
    }
};