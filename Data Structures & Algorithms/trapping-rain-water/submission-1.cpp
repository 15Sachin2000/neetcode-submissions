class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int ans=0;
        for(int i=0;i<height.size();i++){
            while(!stk.empty() && height[stk.top()] <= height[i]){
                int k=stk.top();
                stk.pop();
                if(stk.empty()){
                    break;
                }
                int t=stk.top();
                int mn=min(height[i],height[t]);
                cout<<i<<" "<<t<<endl;
                ans+=(mn-height[k])*(i-t-1);
            }
            stk.push(i);
        }
        return ans;
    }
};
