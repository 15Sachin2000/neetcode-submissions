class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return false;
        sort(nums.rbegin(),nums.rend());
        vector<int> v(k,0);
        return solve(0,nums,v,sum/k);
    }
private:
    bool solve(int t,vector<int> &nums,vector<int> &v,int sum){
        if(t==nums.size()){
            int tmp=v[0];
            for(int i:v){
                cout<<i<<" ";
                if(i!=tmp){ 
                    cout<<endl;
                    return false;
                }
            }
            cout<<endl;
            return true;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]+nums[t]<=sum){
                v[i]+=nums[t];
                if(solve(t+1,nums,v,sum)) return true;
                v[i]-=nums[t];
            }
        }
        return false;
    }
};