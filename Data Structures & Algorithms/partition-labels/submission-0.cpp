class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> b(26,-1);
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(b[s[i]-'a']==-1){
                b[s[i]-'a']=i;
            }
        }
        vector<int> ans;
        int i=0,mx=0,st=0;
        while(i<n){
            if(i>mx){
                ans.push_back(i-st);
                st=i;
            }
            mx=max(mx,b[s[i]-'a']);
            i++;
        }
        ans.push_back(i-st);
        return ans;
    }
};
