class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vis(256,0);
        vis[s[0]]++;
        int l=0,n=s.size(),r=1,ans=1,total=1;
        while(r<n){
            vis[s[r]]++;
            total++;
            int mx=0;
                for(int i:vis){
                    mx=max(mx,i);
                }
                while(total-mx>k){
                    vis[s[l]]--;
                    total--;
                    mx=0;
                    l++;
                for(int i:vis){
                    mx=max(mx,i);
                }
                }
                r++;
                ans=max(ans,r-l);
        }
        return ans;
    }
};
