class Solution {
public:
    vector<string> ans;
    void solve(int i,string &str,vector<string> &dp,string &tmp){
        if(i==str.size()){
            ans.push_back(tmp);
            return;
        }
        int k=stoi(str.substr(i,1));
        for(char c:dp[k]){
            tmp.push_back(c);
            solve(i+1,str,dp,tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        vector<string> dp={{},{},{"abc"},"def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string str;
        solve(0,digits,dp,str);
        return ans;
    }
};
