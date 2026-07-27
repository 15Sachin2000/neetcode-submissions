class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int dif=right-left;
        if(dif==0) return left;
        int mul=1;
        int a=left,b=right;
        while(mul<=dif && a && b){ 
            a/=2;
            b/=2;
            // cout<<a<<" "<<b<<endl;
            mul*=2;
        }
        int ans=0;
        while(a && b){
            if(a%2 & b%2) ans+=mul;
            a/=2;
            b/=2;
            mul*=2;
        }
        return ans;
    }
};