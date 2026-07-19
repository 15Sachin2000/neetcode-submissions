class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size(),n2=t.size();
        if(n2>n1) return "";
        vector<int> target(256,0);
        vector<int> source(256,0);
        for(char c:t){
            target[c]++;
        }
        int count=0;
        for(int i:target){
            if(i)count++;
        }
        int have=0, l=0,r=0,minLen=INT_MAX,st=0;
        while(r<n1){
            source[s[r]]++;
            if(source[s[r]]==target[s[r]]){
                have++;
            }
            while(have==count){
                if(source[s[l]]==target[s[l]]){
                have--;
                }
                source[s[l]]--;
                if(minLen>r-l+1){
                    minLen=r-l+1;
                    st=l;
                }
                l++;
            }
            r++;
        }
        if(minLen==INT_MAX){
            return "";
        }
        return s.substr(st,minLen);
    }
};
