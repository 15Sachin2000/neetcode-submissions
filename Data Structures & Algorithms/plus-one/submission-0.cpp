class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n=digits.size(),c=1;
        for(int i=n-1;i>=0;i--){
            ans.push_back((c+digits[i])%10);
            c=(c+digits[i])/10;
        }
        if(c) ans.push_back(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
