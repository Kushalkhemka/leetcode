class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG;
    TreeAncestor(int n, vector<int>& parent) {
        // time for the binary lifting guys
        LOG = log2(n) + 1;
        up.resize(
            n, vector<int>(LOG, -1)); //<node,j> where j shows the 2jth ancestor

        // fill the first col of the up the ancenstor table using the any
        // traversal take preorder here no need as parent vector is already
        // given
        for (int i = 0; i < parent.size(); i++) {
            up[i][0] = parent[i];
        }

        // now apply the dp
        for (int j = 1; j < LOG; j++) {
            for (int k = 0; k < n; k++) {
                // now put the main recurrence relation for the binary lifting
                if (up[k][j - 1] != -1) {
                    up[k][j] = up[up[k][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int i = 0;
        int nd = node;
        while (k > 0 && nd != -1) {
            int binary = k & 1;
            if (binary == 1) {
                nd = up[nd][i];
            }
            k >>= 1;
            i++;
        }
        return nd;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */