class Solution {
public:
    vector<vector<string>> ans;
    void solve(int i,string &s,vector<vector<int>> &arr,vector<string> &v){
        if(i==s.size()){
            ans.push_back(v);
            return;
        }
        for(int k:arr[i]){
            v.push_back(s.substr(i,k-i));
            solve(k,s,arr,v);
            v.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i].push_back(i+1);
            for(int j=i+1;j<n;j++){
                int p=i,q=j;
                bool isPalindrome=true;
                while(q>p){
                    if(s[p]!=s[q]){
                        isPalindrome=false;
                        break;
                    }
                    q--;
                    p++;
                };
                if(isPalindrome) arr[i].push_back(j+1);
            }
        }
        vector<string> v; 
        solve(0,s,arr,v);
        return ans;
    }
};
