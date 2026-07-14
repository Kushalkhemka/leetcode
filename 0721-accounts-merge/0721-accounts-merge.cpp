class DisjointSet {
public:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int u) {
        if (parent[u] == u) {
            return u;
        }
        return parent[u] = findUPar(parent[u]);
    }
    bool find(int u, int v) { return findUPar(u) == findUPar(v); }

    void unionByRank(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);
        if (uPar_u == uPar_v)
            return;
        if (rank[uPar_u] > rank[uPar_v]) {
            // smaller attach to bigger rank one
            parent[uPar_v] = uPar_u;
        } else if (rank[uPar_u] < rank[uPar_v]) {
            parent[uPar_u] = uPar_v;
        } else {
            parent[uPar_u] = uPar_v;
            // upar_v attach to upar_u so rank of upar_u increass
            rank[uPar_v]++;
        }
    }

    void unionBySize(int u, int v) {
        int uPar_u = findUPar(u);
        int uPar_v = findUPar(v);
        if (uPar_u == uPar_v)
            return;
        if (size[uPar_u] > size[uPar_v]) {
            // smaller attach to bigger rank one
            parent[uPar_v] = uPar_u;
            size[uPar_u] += size[uPar_v];
        } else {
            //<= both cases covered as size increases in all three cases so can
            // be combined
            parent[uPar_u] = uPar_v;
            size[uPar_v] += size[uPar_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts) {
        // first map all the email to ids
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp; //<email,parentID>
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (mp.find(email) != mp.end()) {
                    // if already exists make a connection between both nodes
                    ds.unionByRank(mp[email], i);
                } else {
                    mp[accounts[i][j]] = i;
                }
            }
        }

        // now traverse the map to check for the id with their email
        unordered_map<int, vector<string>> mapping;
        for (auto& it : mp) {
            string email = it.first;
            int node = it.second;
            mapping[ds.findUPar(node)].push_back(email);
        }

        // now traverse mapping
        vector<vector<string>> ans;

        for (auto& it : mapping) {
            vector<string> temp;
            string name = accounts[it.first][0];
            temp.push_back(name);
            sort(it.second.begin(), it.second.end());
            temp.insert(temp.end(), it.second.begin(), it.second.end());

            ans.push_back(temp);
        }

        return ans;
    }
};