class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        unordered_set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        int ans=1;
        for(auto itr:s){
            if(s.find(itr-1)==s.end()){
                int k=itr,tmp=0;
                while(s.find(k)!=s.end()){
                    tmp++;
                    k++;
                }
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};
