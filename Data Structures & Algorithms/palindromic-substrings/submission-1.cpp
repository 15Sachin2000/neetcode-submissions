class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int k=0;
            while(i-k>=0 && i+k<n && s[i-k]==s[i+k]){
                ans++;
                k++;
            }
            int l=i,r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                ans++;
                l--;
                r++;
            }
        }
        return ans;
    }
};
