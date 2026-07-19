class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>> mp(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            for(char c:strs[i]){
                mp[i][c-'a']++;
            }
        }
        vector<bool> vis(n,0);
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            vector<string> tmp;
            tmp.push_back(strs[i]);
            for(int j=i+1;j<n;j++){
                bool isMatch=true;
                for(int k=0;k<26;k++){
                    if(mp[i][k]!=mp[j][k]) isMatch=false;
                }
                if(isMatch){
                    tmp.push_back(strs[j]);
                    vis[j]=true;
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
