class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       map<int,int> mp;
       for(int i:nums){
        mp[i]=1;
       }
       int ans=0;
       for(auto itr:mp){
        mp[itr.first]=1+mp[itr.first-1];
        ans=max(ans,mp[itr.first]);
       }
       return ans;
    }
};
