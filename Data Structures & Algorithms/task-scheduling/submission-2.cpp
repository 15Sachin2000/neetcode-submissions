class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(char c: tasks){
            v[c-'A']++;
        }
        priority_queue<int> pq;
        for(int i:v){
            if(i) pq.push(i);
        }
        int ans=0;
        queue<pair<int,int>> q;
        while(!pq.empty() || !q.empty()){
            ans++;
            while(!q.empty() && q.front().second==ans){
                pq.push(q.front().first);
                q.pop();
            }
            if(pq.empty()){
                continue;
            }
            int k=pq.top();
            pq.pop();
            if(k>1){
                q.push({k-1,ans+n+1});
            }     
        }
        return ans;
    }
};
