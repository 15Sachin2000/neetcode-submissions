class Solution {
public:
    bool makesquare(vector<int>& m) {
        int n=m.size();
        int sum=accumulate(m.begin(),m.end(),0);
        if(n<4 || sum%4!=0) return false;
        sort(m.rbegin(),m.rend());
        vector<int> side(4,0);
        return backtrack(0,m,side,sum/4);
    }
private:
    bool backtrack(int i,vector<int> &m,vector<int> &side,int length){
        if(i==m.size()) return true;
        for(int k=0;k<4;k++){
            if(side[k]+m[i]<=length){
                side[k]+=m[i];
                if(backtrack(i+1,m,side,length)) return true;
                side[k]-=m[i];
            }
        }
        return false;
    }
};