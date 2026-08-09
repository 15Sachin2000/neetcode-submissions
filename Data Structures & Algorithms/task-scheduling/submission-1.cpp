class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(char c:tasks){
            v[c-'A']++;
        }
        sort(v.begin(),v.end());
        int ans=0;
        int carry=0;
        for(int i=25;i>=0;i--){
           if(v[i]==0) break;
           if(carry>=v[i]){
             carry-=v[i];
           }else{
            int tmp=v[i]-carry;
            carry=tmp-1;
            ans+=tmp+(carry*n);
           }
        }
        return ans;        
    }
};
