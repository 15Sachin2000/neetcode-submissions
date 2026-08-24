class Solution {
public:
    int getSum(int a, int b) {
        int ans=0,c=0;
        for(int i=0;i<32;i++){
            int x=(1<<i & a)?1:0;
            int y=(1<<i & b)?1:0;
            int z=x^y^c;
            if(z) ans|=1<<i;
            c=x&y|y&c|c&x;
        }
        return ans;
    }
};
