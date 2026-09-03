class Solution {
public:
    string convertToTitle(int cn) {
        if(cn==0) return "";
        cn--;
        return convertToTitle(cn/26)+char('A'+(cn%26));
    }
};