class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        int p=n<0?-n:n;
        double ans=1,mul=1;
        for(int i=0;i<31;i++){
            if(i==0){
                mul=x;
            }else{
                mul*=mul;
            }
            if(p & (1<<i)){
                ans*=mul;
            }
        }
        return n>0?ans:1.0/ans;
    }
};
