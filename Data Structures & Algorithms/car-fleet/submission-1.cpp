class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,float>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({position[i],(1.0*(target-position[i]))/speed[i]});
        }
        sort(arr.begin(),arr.end());
       int ans=1;
       float mx=arr[n-1].second;
       for(int i=n-2;i>=0;i--){
        if(1.0 * arr[i].second>mx){
            ans++;
            mx=1.0* arr[i].second;
        }
       }
       return ans;
    }
};
