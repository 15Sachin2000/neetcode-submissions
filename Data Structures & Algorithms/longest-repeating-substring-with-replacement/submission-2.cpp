class Solution {
public:
    int characterReplacement(string s, int k) {
        // vector<int> v(26,0);
        // int l=0,ans=1,tmp=0;
        // for(int i=0;i<s.size();i++){
        //     v[s[i]-'A']++;
        //     int mx=1, total=0;
        //     do{
        //         if(total-mx>k){
        //             v[s[l]-'A']--;
        //             l++;
        //         }
        //         mx=1,total=0;
        //         for(int j=0;j<26;j++){
        //             total+=v[j];
        //             mx=max(mx,v[j]);
        //         }
        //     }while(total-mx>k);
        //     ans=max(ans,i-l+1);
        // }
        // return ans;
        vector<int> freq(26, 0);
        int l = 0, maxFreq = 0, ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // if replacements needed > k, shrink window
            if ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
