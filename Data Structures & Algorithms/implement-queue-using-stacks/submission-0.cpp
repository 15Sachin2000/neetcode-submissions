class MyQueue {
public:
    stack<int> stk;
    stack<int> op;
    MyQueue() {
        
    }
    
    void push(int x) {
        stk.push(x);
    }
    
    int pop() {
        while(!stk.empty()){
            op.push(stk.top());
            stk.pop();
        }
        int result=op.top();
        op.pop();
        while(!op.empty()){
            stk.push(op.top());
            op.pop();
        }
        return result;
    }
    
    int peek() {
        while(!stk.empty()){
            op.push(stk.top());
            stk.pop();
        }
        int result=op.top();
        while(!op.empty()){
            stk.push(op.top());
            op.pop();
        }
        return result;
    }
    
    bool empty() {
        return stk.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */