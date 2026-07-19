class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a1=0, a2=0,c1=0,c2=0,n=nums.size();
        for(int i:nums){
            if(i==a1){
                c1++;
            }else if(i==a2){
                c2++;
            }else if(c1==0){
                a1=i;
                c1=1;
            } else if(c2==0){
                a2=i;
                c2=1;
            }else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i:nums){
            if(a1==i) c1++;
            if(a2==i) c2++;
        }
        vector<int> ans;
        if(c1>(n/3)) ans.push_back(a1);
        if(c2>(n/3) && a1!=a2) ans.push_back(a2);
        return ans;
    }
};