class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0)
        pq.push({a,'a'});
        if(b>0)
        pq.push({b,'b'});
        if(c>0)
        pq.push({c,'c'});
        int x=0;
        char pre='q';
        string ans="";
        while(!pq.empty()){
            int f=pq.top().first;
            char ch=pq.top().second;
            pq.pop();

            cout<<f<<" "<<ch<<endl;
            if(pre==ch){
                x++;
                if(x==3){
                    if(pq.empty()) break;
                    ans+=pq.top().second;
                    x=1;
                    pre=pq.top().second;
                    pq.pop();
                    if(pq.top().first-1>0){
                        pq.push({pq.top().first-1,pre});
                    }
                    pq.push({f,ch});
                }else{
                    ans+=ch;
                    if(f-1>0){
                        pq.push({f-1,ch});
                    }
                }
            }else{
                x=1;
                pre=ch;
                ans+=ch;
                if(f-1>0){
                    pq.push({f-1,ch});
                }
            }
        }
        return ans;
    }
};