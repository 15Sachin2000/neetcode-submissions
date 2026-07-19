class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int n=s.length();
        vector<int> vis1(26,0);
        for(char ch:s){
            vis1[ch-'a']++;
        }
        for(char ch:t){
            vis1[ch-'a']--;
        }
        for(int i=0;i<26;i++){
            if(vis1[i]!=0){
                return false;
            }
        }
        return true;
    }
};
