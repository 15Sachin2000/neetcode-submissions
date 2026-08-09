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
        int a1=pq1.top();
        if(pq1.size()>pq2.size()){
            if(num>a1){
                pq2.push(num);
            }else{
                pq1.pop();
                pq1.push(num);
                pq2.push(a1);
            }
        }else{
            int b1=pq2.top();
            if(num<a1){
                pq1.push(num);
            }else{
                pq1.push(b1);
                pq2.pop();
                pq2.push(num);
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()>pq2.size()){
            return pq1.top();
        }
        return (pq1.top()+pq2.top())/(2.0);
    }
};
