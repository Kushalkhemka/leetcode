class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> st;
        unordered_set<string> visited;
        for (const string& s : deadends) {
            st.insert(s);
        }

        queue<pair<string, int>> q;
        q.push({"0000", 0});

        while (!q.empty()) {
            // chng the every character from a to z
            string word = q.front().first;
            string original = word;
            int step = q.front().second;
            int qs = q.size();
            visited.insert(word);
            q.pop();
            if (st.find(word) != st.end()) {
                // we found a deadend word so not explore its neigbhour prune it
                // and skip it since it already got popped so just continue
                continue;
            }
            if (word == target)
                return step;

            for (int i = 0; i < word.length(); i++) {
                // i have to produce the eight state for each word
                for (int m = 0; m < 4; m++) {
                    // mark it visited now so we don't push again when we
                    // get it
                    char c = word[m]; // original char temporarily store
                    word[m] = (c == '9') ? '0' : c + 1;
    
                    // restore original word
                    if (visited.find(word) == visited.end()){
                        q.push({word, step + 1});
                        visited.insert(word);
                    }
                    
                    word[m] = c;
                }

                for (int m = 0; m < 4; m++) {
                    // mark it visited now so we don't push again when we
                    // get it
                    char c = word[m]; // original char temporarily store
                    word[m] = (c == '0') ? '9' : c - 1;
                     // skip visited path don't push into queue
                                  // again
                    // restore original word
                    if (visited.find(word) == visited.end()){
                        q.push({word, step + 1});
                        visited.insert(word);
                    }
                    word[m] = c;
                }
            }
        }
        return -1;
    }
    
};