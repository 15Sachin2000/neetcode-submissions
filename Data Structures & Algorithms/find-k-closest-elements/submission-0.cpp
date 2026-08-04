class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int idx=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        vector<int> ans;
        if(idx==n){
            while(k--){
                ans.push_back(arr[--idx]);
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
        if(idx==0){
            while(k--){
                ans.push_back(arr[idx++]);
            }
            return ans;
        }
        int l=idx-1,r=idx;
        while(l>=0 && r<n && k>0){
            // cout<<l<<" "<<r<<endl;
            int a=abs(arr[l]-x);
            int b=abs(arr[r]-x);
            if(a<=b){
                ans.push_back(arr[l]);
                l--;
            }else{
                ans.push_back(arr[r]);
                r++;
            }
            k--;
        }
        while(l>=0 && k>0){
            ans.push_back(arr[l]);
            l--;
            k--;
        }
        while(r<n && k>0){
            ans.push_back(arr[r]);
            r++;
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};