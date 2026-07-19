class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> stk;
        int n=temp.size();
        vector<int> ans(n,0);
        stk.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!stk.empty() && temp[stk.top()]<=temp[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i]=stk.top()-i;
            }
            stk.push(i);
        }
        return ans;
    }
};
