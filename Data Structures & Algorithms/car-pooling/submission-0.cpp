class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),cmp);
        int i=0,n=trips.size(),curr=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        while(i<n){
            while(!pq.empty() && trips[i][1]>=pq.top().first){
                curr-=trips[pq.top().second][0];
                pq.pop();
            }
            curr+=trips[i][0];
            if(curr>capacity) return false;
            pq.push({trips[i][2],i});
            i++;
        }
        return true;
    }
};