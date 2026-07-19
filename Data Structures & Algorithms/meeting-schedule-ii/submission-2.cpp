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
    int minMeetingRooms(vector<Interval>& it) {
        // sort(it.begin(),it.end(),[](auto& a,auto& b){
        //     if(a.end==b.end) return a.end-a.start<b.end-b.start;
        //     return a.end<b.end;    
        // })
        if(it.size()==0) return 0;
        int ans=0;
        for(int i=0;i<it.size();i++){
            int k=0;
            for(int j=0;j<it.size();j++){
                if(i==j) continue;
                if(it[i].start>it[j].start && it[i].start<it[j].end){
                    cout<<i<<" "<<j<<endl;
                     k++;
                }
            }
            ans=max(ans,k);
        }
        return ans+1;
    }
};
