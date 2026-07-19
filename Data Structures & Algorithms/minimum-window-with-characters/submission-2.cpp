class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v1(256,0);
        vector<int> v2(256,0);
        // for(char c:s){
        //     v1[c]++;
        // }
        for(char c:t){
            v2[c]++;
        }
        string ans="";
        int l=0;
        for(int i=0;i<s.size();i++){
            v1[s[i]]++;
            bool isValid=false;
            do{
                if(!isValid){
                    isValid=true;
                }else{
                    if(ans==""){
                        ans=s.substr(l,i-l+1);
                    }
                    if(ans.size()>i-l+1){
                        ans=s.substr(l,i-l+1);
                    }
                    v1[s[l]]--;
                    l++;
                }
                for(int j=0;j<256;j++){
                    if(v2[j]>v1[j]){
                        isValid=false;
                        break;
                    }
                }
            }while(isValid);
        }
        return ans;
    }
};
