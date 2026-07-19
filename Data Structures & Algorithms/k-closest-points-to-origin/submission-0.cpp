class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<points.size();i++){
            vector<int> v=points[i];
            pq.push({v[0]*v[0]+v[1]*v[1],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back(points[p.second]);
        }
        return ans;
    }
};
