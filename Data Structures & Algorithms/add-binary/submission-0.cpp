class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int n1=a.size(),n2=b.size();
        int i=n1-1,j=n2-1,c=0;
        while(i>=0 || j>=0){
            int q=i>=0 ? a[i]-'0':0;
            int w=j>=0 ? b[j]-'0':0;
            int tmp=c+q+w;
            if(tmp<=1){
                char e=tmp+'0';
                ans.push_back(e);
                c=0;
            }else{
                if(tmp==2){
                    ans.push_back('0');
                }else{
                    ans.push_back('1');
                }
                c=1;
            }
            i--;
            j--;
        }
        if(c) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};