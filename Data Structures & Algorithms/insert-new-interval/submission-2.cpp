class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(vector<int> v:intervals){
            pq.push(v);
        }
        pq.push(newInterval);
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
            int start=v[0],end=v[1];
            while(!pq.empty() && pq.top()[0]<=end){
                end=max(end,pq.top()[1]);
                pq.pop();
            }
            ans.push_back({start,end});
        }
        return ans;
    }
};
