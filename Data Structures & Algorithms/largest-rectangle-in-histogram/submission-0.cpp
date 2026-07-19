class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n=heights.size();
        vector<int> left(n,1);
        for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()){
                left[i]=i+1;
            }else{
                left[i]=i-stk.top();
            }
            stk.push(i);
        }
        stack<int> stk1;
        vector<int> right(n,1);
        for(int i=n-1;i>=0;i--){
            while(!stk1.empty() && heights[stk1.top()]>=heights[i]){
                stk1.pop();
            }
            if(stk1.empty()){
                right[i]=n-i;
            }else{
                right[i]=stk1.top()-i;
            }
            stk1.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(left[i]+right[i]-1)*heights[i]);
        }
        return ans;
    }
};
