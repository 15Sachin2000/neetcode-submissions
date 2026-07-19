class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int n=height.size(),i=0,ans=0;
        while(i<n){
            while(!stk.empty() && height[stk.top()]<=height[i]){
                int top=stk.top();
                int tmp=height[top];
                stk.pop();
                if(!stk.empty()){
                    ans+=(min(height[i],height[stk.top()])-tmp)*(i-stk.top()-1);
                }
                cout<<top<<" "<<i<<endl;
                // ans+=height[top]*(i-top-1);
            }
            stk.push(i);
            i++;
        }
        return ans;
    }
};
