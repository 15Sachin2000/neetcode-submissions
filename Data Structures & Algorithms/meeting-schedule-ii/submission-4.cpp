/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(const Interval &a, const Interval &b){
        if(a.start == b.start){
            return a.end < b.end;
        }
        return a.start < b.start;
    }
    int minMeetingRooms(vector<Interval>& itv) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(itv.begin(),itv.end(),cmp);
        int ans=0;
        for(Interval i:itv){
            if(pq.empty()){
                pq.push(i.end);
                ans++;
            }else if(pq.top()>i.start){
                ans++;
                pq.push(i.end);
            }else{
                pq.pop();
                pq.push(i.end);
            }
        }
        return ans;
    }
};
