class Solution {
public:
    bool validPalindrome(string s) {
        int count=1,i=0,j=s.size()-1;
        return solve(s,i,j,count);
    }
private:
    bool solve(string& s,int i,int j,int count){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else if(count){
                return solve(s,i+1,j,0) || solve(s,i,j-1,0);
            }else{
                return false;
            }
        }
        return true;
    }
};