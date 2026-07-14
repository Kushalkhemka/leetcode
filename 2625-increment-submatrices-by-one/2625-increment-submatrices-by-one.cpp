class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n, vector<int>(n, 0));

        for (int i = 0; i < queries.size(); i++) {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];

            for (int j = r1; j <= r2; j++) {
                diff[j][c1] += 1;
                if (c2 + 1 < n)
                    diff[j][c2 + 1] -= 1;
            }

            // just take prefix sum of the diff array
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n; j++) {
                // we traverse every col for each ith row
                diff[i][j] = diff[i][j - 1] + diff[i][j];
            }
        }
        return diff;
    }
};