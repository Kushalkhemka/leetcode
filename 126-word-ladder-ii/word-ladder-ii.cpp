class Solution {
   public:
    vector<vector<string>> findLadders(const string &startWord,
                                       const string &targetWord,
                                       const vector<string> &wordList) {
        unordered_set<string> st;
        vector<vector<string>> ans;

        for (const string &s : wordList) {
            st.insert(s);
        }

        if (st.find(targetWord) == st.end()) return {};

        unordered_map<string, vector<string>> parent;  // changed: stores parents instead of full paths
        unordered_map<string, int> dist;               // changed: stores shortest level of each word

        queue<string> q;  // changed: queue stores only words, not whole paths
        q.push(startWord);
        dist[startWord] = 0;

        if (st.find(startWord) != st.end()) st.erase(startWord);

        bool found = false;  // changed: stop after shortest level is found

        while (!q.empty() && !found) {
            int qSize = q.size();
            vector<string> used;  // words used in current level

            for (int k = 0; k < qSize; k++) {
                string word = q.front();
                q.pop();

                string temp = word;

                for (int i = 0; i < temp.length(); i++) {
                    char old = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == old) continue;  // changed: avoid generating same word

                        temp[i] = c;

                        if (st.find(temp) != st.end()) {
                            if (dist.find(temp) == dist.end()) {
                                dist[temp] = dist[word] + 1;  // changed
                                q.push(temp);                 // changed
                                used.push_back(temp);         // changed
                            }

                            if (dist[temp] == dist[word] + 1) {
                                parent[temp].push_back(word);  // changed
                            }

                            if (temp == targetWord) {
                                found = true;  // changed
                            }
                        }
                    }

                    temp[i] = old;
                }
            }

            for (auto &it : used) {
                st.erase(it);
            }
        }

        if (!found) return {};

        vector<string> path;
        path.push_back(targetWord);

        function<void(string)> dfs = [&](string word) {
            if (word == startWord) {
                vector<string> curr = path;
                reverse(curr.begin(), curr.end());
                ans.push_back(curr);
                return;
            }

            for (auto &p : parent[word]) {
                path.push_back(p);
                dfs(p);
                path.pop_back();
            }
        };

        dfs(targetWord);

        return ans;
    }
};