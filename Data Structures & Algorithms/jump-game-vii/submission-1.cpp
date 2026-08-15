class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1') return false;
        int i=0,mx=0,mn=0;
        vector<bool> reach(n,false);
        reach[0]=true;
        for(int i=0;i<n;i++){
            if(reach[i]){
                int a=i+minJump;
                int b=min(i+maxJump,n-1);
                int tmp=i;
                if(a<=mx) tmp=mx;
                else tmp=a;
                while(tmp<=b){
                    if(s[tmp]=='0') reach[tmp]=true;
                    tmp++;
                }
                mx=i+maxJump;
            }else if(mx<i) return false;
        }
        return reach[n-1];
    }
};