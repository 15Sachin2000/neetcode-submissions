class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& it) {
        vector<vector<int>> ans;
        sort(it.begin(),it.end());
        int start=it[0][0],end=it[0][1];
        for(int i=1;i<it.size();i++){
            if(it[i][0]>end){
                ans.push_back({start,end});
                start=it[i][0];
                end=it[i][1];
            }else{
                start=min(start,it[i][0]);
                end=max(end,it[i][1]);
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};
