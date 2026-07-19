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
    bool canAttendMeetings(vector<Interval>& it) {
        sort(it.begin(),it.end(),[](auto& x, auto& y) {
            return x.start < y.start;
        });
        for(int i=1;i<it.size();i++){
            if(it[i].start<it[i-1].end){
                return false;
            }
        }
        return true;
    }
};
