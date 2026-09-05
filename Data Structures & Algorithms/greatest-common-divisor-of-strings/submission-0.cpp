class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1) return "";
        int n1=str1.size(),n2=str2.size();
        if(n2>n1) swap(n1,n2);
        int l=gcd(n1,n2);
        return str1.substr(0,l);
    }
private:
    int gcd(int a,int b){
        if(a%b==0) return b;
        return gcd(b,a%b);
    }
};