class Solution {
public:
    bool checkBob(int s,int e,vector<int> &v,int sa,int sb){
        if(s==e){
            return sb>sa;
        }
        return !checkAlice(s+1,e,v,sa,sb+v[s]) || !checkAlice(s,e-1,v,sa,sb+v[e]);
    }
    bool checkAlice(int s,int e,vector<int> &v,int sa,int sb){
        if(s==e){
            return sa>sb;
        }
        return !checkBob(s+1,e,v,sa+v[s],sb) || !checkBob(s,e-1,v,sa+v[e],sb);
    }
    bool stoneGame(vector<int>& piles) {
        return true;
        return checkAlice(0,piles.size()-1,piles,0,0);
    }
};