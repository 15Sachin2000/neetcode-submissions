class MinStack {
public:
stack<int> stk;
stack<int> mnStk;
    MinStack() {
        stk=stack<int>();
        mnStk=stack<int>();
    }
    
    void push(int val) {
        stk.push(val);
        mnStk.push(min(val,mnStk.empty()?val:mnStk.top()));
    }
    
    void pop() {
        stk.pop();
        mnStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mnStk.top();
    }
};
