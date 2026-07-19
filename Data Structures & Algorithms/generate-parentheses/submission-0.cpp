class Solution {
public:
vector<string> str;
    void solve(int open,int close,int total,string str,vector<string> &ans){
        if(open==close && open==total){
            ans.push_back(str);
            return;
        }
        if(open==close){
            string newStr=str+"(";
            solve(open+1,close,total,newStr,ans);
            return;
        }
        if(open==total){
             string newStr=str+")";
            solve(open,close+1,total,newStr,ans);
            return;
        }
        string newStr=str+"(";
        solve(open+1,close,total,newStr,ans);
        string newStr1=str+")";
            solve(open,close+1,total,newStr1,ans);
    }
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
       solve(0,0,n,"",ans);
       return ans;
    }
};
