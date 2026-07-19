class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Switch to a MAX-HEAP (default priority queue in C++)
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        int x = 0;
        char pre = 'q';
        string ans = "";
        
        while (!pq.empty()) {
            int f = pq.top().first;
            char ch = pq.top().second;
            
            if (pre == ch) {
                x++;
                if (x == 3) {
                    pq.pop(); // Pop the 1st element
                    
                    if (pq.empty()) break; // No 2nd element available to break the streak
                    
                    // Correctly read and POP the 2nd element
                    auto next_top = pq.top();
                    pq.pop();
                    
                    ans += next_top.second;
                    x = 1;
                    pre = next_top.second;
                    
                    // Re-insert modified elements
                    if (next_top.first - 1 > 0) {
                        pq.push({next_top.first - 1, next_top.second});
                    }
                    pq.push({f, ch}); // Push the 1st element back
                } else {
                    ans += ch;
                    pq.pop();
                    if (f - 1 > 0) {
                        pq.push({f - 1, ch});
                    }
                }
            } else {
                x = 1;
                pre = ch;
                ans += ch;
                pq.pop();
                if (f - 1 > 0) {
                    pq.push({f - 1, ch});
                }
            }
        }
        return ans;
    }
};