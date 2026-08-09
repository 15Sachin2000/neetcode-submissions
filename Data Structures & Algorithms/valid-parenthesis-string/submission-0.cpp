class Solution {
public:
    bool checkValidString(string s) {
        int left=0,wild=0;
        for(char c:s){
            if(c=='('){
                left++;
            }else if(c=='*'){
                wild++;
            }else{
                if(left>0){
                    left--;
                }else if(wild>0){
                    wild--;
                }else{
                    return false;
                }
            }
        }
        return wild>=left;
    }
};
