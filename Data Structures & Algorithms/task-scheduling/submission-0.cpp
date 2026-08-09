class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        for(char c:tasks){
            v[c-'A']++;
        }
        sort(v.begin(),v.end());
        int ans=v[25]+(v[25]-1)*n;
        for(int i=24;i>=0;i--){
            if(v[i]==v[25]){
                ans++;
            }
        }
        return ans;        
    }
};
