class Solution {
public:
    bool isVectorEqual(vector<int> &v1,vector<int> &v2){
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        if(n1>n2) return false;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i=0;i<n1;i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        if(isVectorEqual(v1,v2)){
            return true;
        }
        for(int i=n1;i<n2;i++){
            v2[s2[i-n1]-'a']--;
            v2[s2[i]-'a']++;
            if(isVectorEqual(v1,v2)){
            return true;
        }
        }
        return false;
    }
};
