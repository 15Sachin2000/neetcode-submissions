class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_map<int,bool> mp;
       for(int i:nums){
        mp[i]=true;
       }
       vector<int> arr;
       for(int i:nums){
        if(mp.find(i-1)==mp.end()){
            arr.push_back(i);
        }
       }
       int ans=0;
       for(int i:arr){
        int tmp=i;
        while(mp.find(tmp)!=mp.end()){
            tmp++;
            ans=max(ans,tmp-i);
        }
       }
       return ans;
    }
};
