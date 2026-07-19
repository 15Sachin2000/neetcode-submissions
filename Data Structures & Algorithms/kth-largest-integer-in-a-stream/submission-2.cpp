class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
int q;
    KthLargest(int k, vector<int>& nums) {
        q=k;
        for(int n:nums){
            if(pq.size()==k){
                int top=pq.top();
                if(n>top){
                    pq.pop();
                    pq.push(n);
                }
            }else{
                pq.push(n);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()==q){
                int top=pq.top();
                if(val>top){
                    pq.pop();
                    pq.push(val);
                }
        }else{
            pq.push(val);
        }
        return pq.top();
    }
};
