class Solution {
private:
    bool cmp(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]) return a[1]-a[0]<b[1]-b[0];
        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& it) {
        sort(it.begin(),it.end(),[](vector<int> &a,vector<int> &b){
            if(a[1]==b[1]) return a[1]-a[0]<b[1]-b[0];
            return a[1]<b[1];
        });
        int ans=0,mx=it[0][1];
        for(int i=1;i<it.size();i++){
            if(it[i][0]<mx){
                ans++;
            }else{
                mx=it[i][1];
            }
        }
        return ans;
    }
};
