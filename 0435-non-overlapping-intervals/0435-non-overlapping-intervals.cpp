class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        //[1,2],[1,3],[2,3],[3,4]
        int cnt = 0;
        int prevStart = intervals[0][0];
        int prevEnd = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (prevStart == intervals[i][0] && prevEnd <= intervals[i][1]) {
                // to baad wala hta do
                cnt++;
                // check kro konsa htana h wo hategra jiska ending time more
                // hogha bada hogha
            } else if (intervals[i][0] < prevEnd) {
                cnt++;
                if (prevEnd > intervals[i][1]) {
                    prevStart = intervals[i][0];
                    prevEnd = intervals[i][1];
                }
            } else {
                prevStart = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }
        return cnt;
    }
};