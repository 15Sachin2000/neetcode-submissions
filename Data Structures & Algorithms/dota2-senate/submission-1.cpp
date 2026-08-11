class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> r,d;
        for(int i=0;i<n;i++){
            if(senate[i]=='R') r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()){
            int a=r.front();
            int b=d.front();
            r.pop();
            d.pop();
            if(a<b) r.push(a+n);
            else d.push(b+n);
        }
        if(r.empty()) return "Dire";
        return "Radiant";
    }
};