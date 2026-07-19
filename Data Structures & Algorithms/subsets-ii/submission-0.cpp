class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       int n=nums.size();
       unordered_set<string> st;
       vector<vector<int>> ans;
       for(int i=0;i<(1<<n);i++){
            vector<int> tmp;
            string s="";
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    s+=to_string(nums[j])+",";
                    tmp.push_back(nums[j]);
                }
            }
            sort(s.begin(),s.end());
            if(st.find(s)==st.end()){
                ans.push_back(tmp);
                st.insert(s);
            }
       } 
       return ans;
    }
};
