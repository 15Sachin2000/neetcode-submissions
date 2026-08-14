class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        int a=0,b=1,c=1,i=2;
        while(i<n){
            int tmp=c;
            c+=a+b;
            a=b;
            b=tmp;
            i++;
        }
        return c;
    }
};