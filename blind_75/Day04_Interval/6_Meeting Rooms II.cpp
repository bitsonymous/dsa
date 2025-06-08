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
    struct compare{
        bool operator()(const Interval &a, const Interval &b){
            return a.end > b.end;
        }
    };
    int minMeetingRooms(vector<Interval>& intv) {
        int n = intv.size();
        if(n == 0) return 0;
        priority_queue<Interval, vector<Interval>, compare> pq;
        sort(intv.begin(), intv.end(), [](const Interval &a, const Interval &b){
        return a.start < b.start;
    });
        pq.push(intv[0]);
        for(int i = 1; i<n; i++){
            if(pq.top().end <= intv[i].start){
                pq.pop();
            }
            pq.push(intv[i]);
        }
        return pq.size();
    }
};
