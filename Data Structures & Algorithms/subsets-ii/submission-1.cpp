class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_set<string> s;
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                if(i & 1<<j){
                    tmp.push_back(nums[j]);
                }
            }
            string str="";
            vector<int> ptr=tmp;
            sort(ptr.begin(),ptr.end());
            for(int i:ptr){
                str+=to_string(i)+",";
            }
            if(s.find(str)==s.end()){
                s.insert(str);
                cout<<i<<"+"<<str<<endl;
                ans.push_back(tmp);
            }
            else{
                cout<<i<<" "<<str<<endl;
            }
        }
        return ans;
    }
};
