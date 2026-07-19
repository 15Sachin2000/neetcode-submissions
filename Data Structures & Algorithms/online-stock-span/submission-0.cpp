class StockSpanner {
public:
    stack<pair<int,int>> stk;
    int count;
    StockSpanner() {
        count=0;
    }
    
    int next(int price) {
        count++;
        int ans=count;
        while(!stk.empty() && stk.top().first<=price) stk.pop();
        if(!stk.empty()){
            ans = count - stk.top().second;
        }
        stk.push({price,count});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */