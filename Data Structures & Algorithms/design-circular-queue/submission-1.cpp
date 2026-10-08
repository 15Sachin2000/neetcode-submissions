class MyCircularQueue {
public:
    vector<int> q;
    int s,e,n;
    MyCircularQueue(int k) {
        q.reserve(k);
        s=-1,e=-1,n=k;
    }
    
    bool enQueue(int value) {
        if(isEmpty()){
            s=0,e=0;
            q[0]=value;
            return true;
        }else if(!isFull()){
            e=(e+1)%n;
            q[e]=value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(s==e){
            s=-1;
            e=-1;
        }else{
            s=(s+1)%n;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[s];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[e];
    }
    
    bool isEmpty() {
        return s==e && s==-1;
    }
    
    bool isFull() {
        return (e+1)%n==s;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */