class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0) return "";
        string s=strs[0];
        int q=s.size();
        for(int i=1;i<n;i++){
            int j=0,k=min(q,(int)strs[i].size());
            while(j<k && s[j]==strs[i][j]){
                j++;
            }
            if(j==0) return "";
            q=j;
        }
        return s.substr(0,q);
    }
};