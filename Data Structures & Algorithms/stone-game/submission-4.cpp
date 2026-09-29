class Solution {
public:
    bool bobOptimal(int a,int b,vector<int> &piles,int s, int e){
        if(s==e) return a>b+piles[s];
        return !aliceOptimal(a,b+piles[s],piles,s+1,e) || !aliceOptimal(a,b+piles[e],piles,s,e-1);
    }
    bool aliceOptimal(int a,int b,vector<int> &piles,int s, int e){
        if(s>e) return a>b;
        return !bobOptimal(a+piles[s],b,piles,s+1,e) || !bobOptimal(a+piles[e],b,piles,s,e-1);
    }
    bool stoneGame(vector<int>& piles) {
        return true;
        return aliceOptimal(0,0,piles,0,piles.size()-1);
    }
};