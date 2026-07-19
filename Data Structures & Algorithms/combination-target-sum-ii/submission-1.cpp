class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<string> us;
    void solve(int i,int sum,vector<int> &arr,vector<int> &tmp,string s){
        if(sum==0){
            if(us.find(s)==us.end()){
                us.insert(s);
                ans.push_back(tmp);
            }
            return;
        }
        if(i==arr.size() || sum<0) return;
        tmp.push_back(arr[i]);
        solve(i+1,sum-arr[i],arr,tmp,s+to_string(arr[i]));
        tmp.pop_back();
        solve(i+1,sum,arr,tmp,s);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(),candidates.end());
        solve(0,target,candidates,tmp,"");
        return ans;
    }
};
