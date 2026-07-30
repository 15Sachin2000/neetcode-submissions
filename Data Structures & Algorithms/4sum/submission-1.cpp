class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int l=j+1,r=n-1;
                long long t=1ll*target-1ll*nums[i]-1ll*nums[j];
                while(l<r){
                    long long sum=1ll*nums[l]+1ll*nums[r];
                    if(sum==t){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        int k=l;
                        while(l<n && nums[l]==nums[k])
                        l++;
                        k=r;
                        while(r>l && nums[r]==nums[k])
                        r--;
                    }else if(sum>t){
                        r--;
                    }else{
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};