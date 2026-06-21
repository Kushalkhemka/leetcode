class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) { // changed: const reference avoids unnecessary modification risk
        if (a[0] == b[0])
            return (a[1] < b[1]);
        return (a[0] < b[0]);
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort by the starting time
        sort(intervals.begin(), intervals.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> pq; 

        int rooms = 0; 

        for (int i = 0; i < intervals.size(); i++) {
            while (!pq.empty() && pq.top() <= intervals[i][0]) { 
                pq.pop(); 
            }

            pq.push(intervals[i][1]); 
            rooms = max(rooms, (int)pq.size());
        }

        return rooms;
    }
};