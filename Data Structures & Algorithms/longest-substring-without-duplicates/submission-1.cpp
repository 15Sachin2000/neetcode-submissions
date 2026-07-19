class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
        int l=1,n=s.size(),start=0,i=1,ans=1;
        vector<int> vis(256,0);
        vis[s[0]]++;
        while(i<n){
            vis[s[i]]++;
            while(vis[s[i]]>1){
                vis[s[start]]--;
                start++;
            }
            i++;
            ans=max(ans,i-start);
        }
        return ans;
    }
};
