class Solution {
public:
    int reverse(int x) {
        bool isNegative=x<0;
        if(isNegative) x*=-1;
        string s=to_string(x);
        int i=0,j=s.size()-1;
        while(j>i){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        long long l=stoll(s);
        if((!isNegative && l>INT_MAX) || (isNegative && l>(1ll*INT_MAX + 1*1ll))) return 0;
        return isNegative ?-1*l:l;
    }
};
