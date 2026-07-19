class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        unordered_map<int,int> mp;
        for(int i:nums){
            if(mp.find(i-1)!=mp.end()){
                mp[i]=1+mp[i-1];
            }else{
                mp[i]=1;
            }
            ans=max(ans,mp[i]);
        }
        return ans;
    }
};
