class Solution {
public:
    bool isValid(char c){
        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            if(!isValid(s[i])){
                i++;
                continue;
            }
            if(!isValid(s[j])){
                j--;
                continue;
            }
            if(tolower(s[i])!=tolower(s[j])){
                cout<<i<<" "<<j<<" "<<s[i]<<" "<<s[j]<<endl;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
