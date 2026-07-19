class MedianFinder {
public:
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>> mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty()){
            mx.push(num);
            return;
        }
        if(mn.empty()){
            if(mx.top()>num){
                mn.push(mx.top());
                mx.pop();
                mx.push(num);
            }else{
                mn.push(num);
            }
            return;
        }
        if(num>mn.top()){
            mn.push(num);
        }else{
            mx.push(num);
        }
        int r=(mn.size()+mx.size())%2;
        while(mx.size()-mn.size()!=r){
            if(mn.size()>mx.size()){
                int a=mn.top();
                mn.pop();
                mx.push(a);
            }else{
                int a=mx.top();
                mx.pop();
                mn.push(a);
            }
        }
    }
    
    double findMedian() {
         int r=(mn.size()+mx.size())%2;
         if(r==1){
            return mx.top()*1.0;
         }else{
            return ((mn.top()+mx.top())*1.0)/2.0;
         }
    }
};
