class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intv) {
        int n = intv.size();
        int count = 0;
        sort(intv.begin(), intv.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int prev = intv[0][1];
        for(int i = 1; i<n; i++){
            if(prev > intv[i][0]){
                count++;
            }else{
                prev = intv[i][1];
            }
        }
        return count;
    }
};