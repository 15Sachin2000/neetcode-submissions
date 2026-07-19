class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(int i:asteroids){
            while(i<0 && !stk.empty() && stk.top()>0 && -1*i>stk.top()) stk.pop();
            if(!stk.empty() && i<0){
                if(stk.top()==-1*i){
                    stk.pop();
                }else if(stk.top()<0){
                    stk.push(i);
                }
            }else{
                stk.push(i);
            }
        }
        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};