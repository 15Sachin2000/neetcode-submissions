class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size(),s=0,mx=0;
        vector<vector<int>> tmp;
        vector<int> ans;
        for(int i=0;i<n;i++){
            tmp.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(tmp.begin(),tmp.end());
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        while(!pq.empty() || s<n){
            if(pq.empty()){
                pq.push({tmp[s][1],tmp[s][2],tmp[s][0]});
                s++;
                continue;
            }
            vector<int> tp=pq.top();
            pq.pop();
            ans.push_back(tp[1]);
            mx=max(mx,tp[2])+tp[0];
            while(s<n && tmp[s][0]<=mx){
                pq.push({tmp[s][1],tmp[s][2],tmp[s][0]});
                s++;
            }
        }
        return ans;
    }
};