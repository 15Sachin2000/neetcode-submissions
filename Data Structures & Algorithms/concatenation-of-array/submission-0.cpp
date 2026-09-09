class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(2*n);
        int i=0;
        while(i<2*n){
            v[i]=nums[i%n];
            i++;
        }
        return v;
    }
};