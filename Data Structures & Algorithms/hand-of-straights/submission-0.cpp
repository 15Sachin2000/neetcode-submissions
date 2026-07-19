class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        sort(hand.begin(),hand.end());
        if(n%groupSize!=0) return false;
        int group=n/groupSize;
        vector<vector<int>> v(group);
        for(int i:hand){
            // for(int j=0;j<group;j++){
            //     if(v[j].size==)
            // }
            int j=0;
            while(j<group && v[j].size() && (v[j][1]==groupSize || v[j][0]!=(i-1))) j++;
            // cout<<
            if(j==group) return false;
            if(!v[j].size()){
                v[j]={i,1};
            }else{
                v[j][0]=i;
                v[j][1]++;
            }
        }
        return true;
    }
};
