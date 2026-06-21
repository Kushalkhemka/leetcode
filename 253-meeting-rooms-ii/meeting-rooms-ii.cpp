class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return (a[1] < b[1]);
        return (a[0] < b[0]);
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort by the starting time
        multiset<int> st;

        sort(intervals.begin(), intervals.end(), cmp);

        int n = intervals.size();

        st.insert(intervals[0][1]);

        for (int i = 1; i < n; i++) {
            if (*st.begin() <= intervals[i][0]) { 
                st.erase(st.begin()); 
            }

            st.insert(intervals[i][1]); 
        }

        return st.size();
    }
};