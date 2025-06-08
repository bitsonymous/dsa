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
    static bool compare(const Interval &a, const Interval &b){
        return a.end < b.end;
    }
    bool canAttendMeetings(vector<Interval>& intv) {
        int n = intv.size();
        if(n == 0) return true;
        sort(intv.begin(), intv.end(), compare);
        int prev = intv[0].end;
        for(int i = 1; i<n; i++){
            if(prev > intv[i].start) return false;
            prev = intv[i].end;
        }
        return true;
    }
};
