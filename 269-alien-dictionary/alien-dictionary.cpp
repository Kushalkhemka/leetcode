
class Solution {
public:
    bool dfs(int node, const vector<vector<int>>& adj, vector<int>& visited,
             stack<int>& s) {
        visited[node] = 1; //  1 means current path

        for (auto it : adj[node]) {
            if (visited[it] == 0) {
                if (dfs(it, adj, visited, s)) { //  cycle return handle
                    return true;
                }
            } else if (visited[it] == 1) { // cycle detected
                return true;
            }
        }

        visited[node] = 2; //  fully processed
        s.push(node);
        return false;
    }

    string topoSort(const int V, const vector<vector<int>>& adj, const vector<int> &present) {
        // 0 based indexed graph
        stack<int> s;
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (present[i] && !visited[i]) {
                if (dfs(i, adj, visited, s)) { // cycle check
                    return "";
                }
            }
        }
        string ans;
        while (!s.empty()) {
            ans += (char)(s.top() + 'a');
            s.pop();
        }
        return ans;
    }
    string alienOrder(vector<string>& dict) {
        // first build the string
        // we don't know N AND K as in Tuf, so we need to assume all 26
        // alphabets first and then check present to figure out total unique
        // letter used in given string.

        //also letters may be not contiguous as in the striver one 
        int V = 26;
        vector<vector<int>> adj(V);
        vector<int> present(V, 0);

       

        for (const auto& word : dict) {
            for (char ch : word) {
                if (!present[ch - 'a']) {
                    present[ch - 'a'] = 1;
                }
            }
        }
        for (int i = 0; i < dict.size() - 1; i++) {
            string a = dict[i];
            string b = dict[i + 1];

            // initialize the two pointers for both string to match the prefix
            // until different
            int j = 0;
            int k = 0;
            while (j < a.size() && k < b.size() && a[j] == b[k]) {
                j++;
                k++;
            }

            if (k == b.size() && j < a.size()) {
                return "";
            }

            if (j < a.size() && k < b.size()) { // out of bound protection
                 int u = a[j] - 'a';
                int v = b[k] - 'a';

                adj[u].push_back(v);

                // avoid duplicate edge
                bool found = false;
                for (const auto &it : adj[u]) {
                    if (it == v) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    adj[u].push_back(v);
                }
            }
        }

        return topoSort(V, adj,present);

        // our graph is ready now it's time for the topo sort
    }
};
