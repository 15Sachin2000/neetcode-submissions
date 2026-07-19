class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x=INT_MIN,y=INT_MIN,z=INT_MIN;
        for(vector<int> v:triplets){
            if(v[0]>target[0] || v[1]>target[1] || v[2]>target[2]){
                continue;
            };
            x=max(x,v[0]);
            y=max(y,v[1]);
            z=max(z,v[2]);
        };
        return ( x==target[0] && y==target[1] && z==target[2]);
    }
};
