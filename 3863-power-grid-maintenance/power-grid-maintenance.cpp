#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>

class DisjointSet {
public:
    std::vector<int> parent, rank;
    std::vector<int> min_online;

    DisjointSet(int n, const std::vector<bool>& is_online_at_end) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        min_online.resize(n + 1);

        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
            if (i > 0 && is_online_at_end[i]) {
                min_online[i] = i;
            } else {
                min_online[i] = n + 1;
            }
        }
    }

    int findUPar(int u) {
        if (u == parent[u]) {
            return u;
        }
        return parent[u] = findUPar(parent[u]);
    }

    void unionByRank(int u, int v) {
        int p_u = findUPar(u);
        int p_v = findUPar(v);
        if (p_u == p_v) return;

        int old_min_u = min_online[p_u];
        int old_min_v = min_online[p_v];

        if (rank[p_u] > rank[p_v]) {
            parent[p_v] = p_u;
            min_online[p_u] = std::min(old_min_u, old_min_v);
        } else if (rank[p_u] < rank[p_v]) {
            parent[p_u] = p_v;
            min_online[p_v] = std::min(old_min_u, old_min_v);
        } else {
            parent[p_u] = p_v;
            rank[p_v]++;
            min_online[p_v] = std::min(old_min_u, old_min_v);
        }
    }
};

class Solution {
public:
    std::vector<int> processQueries(int c, std::vector<std::vector<int>>& connections, std::vector<std::vector<int>>& queries) {
        std::vector<bool> is_online_at_end(c + 1, true);
        std::vector<int> offline_requests(c + 1, 0);
        
        for (const auto& query : queries) {
            if (query[0] == 2) {
                is_online_at_end[query[1]] = false;
                offline_requests[query[1]]++;
            }
        }

        DisjointSet ds(c, is_online_at_end);

        for (const auto& conn : connections) {
            ds.unionByRank(conn[0], conn[1]);
        }
        
        std::vector<int> results;
        
        for (int i = queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0];
            int station = queries[i][1];

            if (type == 1) {
                int answer;
                bool is_offline_now = (offline_requests[station] > 0);
                
                if (!is_offline_now) {
                    answer = station;
                } else {
                    int root = ds.findUPar(station);
                    int min_id = ds.min_online[root];
                    answer = (min_id > c) ? -1 : min_id;
                }
                results.push_back(answer);

            } else {
                offline_requests[station]--;
                if (offline_requests[station] == 0) {
                    int root = ds.findUPar(station);
                    ds.min_online[root] = std::min(ds.min_online[root], station);
                }
            }
        }
        
        std::reverse(results.begin(), results.end());
        return results;
    }
};