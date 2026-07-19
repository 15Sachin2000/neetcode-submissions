class MinStack {
public:
list<int> l;
    MinStack() {
        l=list<int>();
    }
    
    void push(int val) {
        l.push_back(val);
    }
    
    void pop() {
        l.pop_back();
    }
    
    int top() {
        return l.back();
    }
    
    int getMin() {
        int mn=INT_MAX;
        for(auto itr:l){
            mn=min(mn,itr);
        }
        return mn;
    }
};
