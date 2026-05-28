class Node {
public:
    int links[26];
    int flag;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = -1;
        }
        flag = 0;
    }

    bool containsKey(char ch) { return links[ch - 'a'] != -1; }

    void put(char ch, int nodeIdx) { links[ch - 'a'] = nodeIdx; }
    int getNext(char ch) { return links[ch - 'a']; }
};

class Trie {
public:
    vector<Node> nodes;

    Trie(int totalLen) {
        nodes.reserve(totalLen + 1);
        nodes.push_back(Node());
    }

    void insert(const string& word, int idx) {
        int node = 0;
        nodes[node].flag = idx;

        for (int i = (int)word.length() - 1; i >= 0; i--) {
            char c = word[i];
            if (!nodes[node].containsKey(c)) {
                nodes[node].put(c, nodes.size());
                nodes.push_back(Node());
            }
            node = nodes[node].getNext(c);
            nodes[node].flag = idx;
        }
    }

    int startsWith(const string& word) {
        int node = 0;

        for (int i = (int)word.length() - 1; i >= 0; i--) {
            char c = word[i];

            if (!nodes[node].containsKey(c)) {
                return nodes[node].flag;
            }
            node = nodes[node].getNext(c);
        }
        return nodes[node].flag;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        int n = wordsContainer.size();

        vector<int> order(n);
        int totalLen = 0;

        for (int i = 0; i < n; i++) {
            order[i] = i;
            totalLen += wordsContainer[i].length();
        }

        sort(order.begin(), order.end(), [&](int a, int b) {
            if (wordsContainer[a].length() == wordsContainer[b].length()) {
                return a > b;
            }
            return wordsContainer[a].length() > wordsContainer[b].length();
        });

        Trie T(totalLen);
        vector<int> ans;

        for (int idx : order) {
            T.insert(wordsContainer[idx], idx);
        }

        for (int i = 0; i < wordsQuery.size(); i++) {
            ans.push_back(T.startsWith(wordsQuery[i]));
        }

        return ans;
    }
};