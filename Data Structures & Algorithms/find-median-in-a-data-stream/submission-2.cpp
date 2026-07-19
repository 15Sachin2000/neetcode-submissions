class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>> pq2;
    priority_queue<int> pq1;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(pq1.empty()){
         pq1.push(num);
         return;
       }
       if(pq1.size()>pq2.size()){
         if(num>pq1.top()){
            pq2.push(num);
         }else{
            pq2.push(pq1.top());
            pq1.pop();
            pq1.push(num);
         }
       }else{
        if(num<pq2.top()){
            pq1.push(num);
        }else{
            pq1.push(pq2.top());
            pq2.pop();
            pq2.push(num);
        }
       }
    }
    
    double findMedian() {
        cout<<pq1.size()<<" "<<pq2.size()<<endl;
        if(!pq1.empty()){
            cout<<pq1.top()<<endl;
        }
        if(!pq2.empty()){
            cout<<pq2.top()<<endl;
        }
        if(pq1.size()>pq2.size()){
            return pq1.top();
        }
        return (pq1.top()+pq2.top())/(2.0);
    }
};
