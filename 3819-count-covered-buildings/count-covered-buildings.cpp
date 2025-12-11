class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        // just like n queen make the 2  1-D array for the row and col storage
        // of acquired poisition
        vector<int> minRow(n + 1, 1e9), maxRow(n + 1, INT_MIN),
            minCol(n + 1, 1e9), maxCol(n + 1, INT_MIN);

        for (auto& e : buildings) {
            minRow[e[0]] = min(minRow[e[0]], e[1]);
            maxRow[e[0]] = max(maxRow[e[0]], e[1]);
            minCol[e[1]] = min(minCol[e[1]], e[0]);
            maxCol[e[1]] = max(maxCol[e[1]], e[0]);
        }
        int count = 0;
        for (auto& e : buildings) {
            if (minRow[e[0]] < e[1] && maxRow[e[0]] > e[1] &&
                minCol[e[1]] < e[0] && maxCol[e[1]] > e[0])
                count++;
        }
        return count;
    }
};