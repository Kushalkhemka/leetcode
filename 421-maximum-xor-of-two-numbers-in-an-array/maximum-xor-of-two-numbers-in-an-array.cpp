class Node {
   public:
    Node* links[2];
    bool flg;

    Node() {
        for (int i = 0; i < 2; i++) {
            links[i] = NULL;
        }

        flg = false;
    }

    bool containsKey(int b) {
        return links[b] != nullptr;
        // it exists if true
    }

    void put(int b, Node* node) {
        // so we expect ch and pointer to node the ref node
        links[b] = node;
    }

    // move to next node
    Node* getNext(int b) { return links[b]; }

    void setFlag() { flg = true; }

    bool isEnd() { return flg; }
};

class Trie {
   public:
    Node* root;
    Trie() { root = new Node(); }
    void insert(int n) {
        // first convert the number
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;
            if (!node->containsKey(bit)) {
                // not exists then we need to insert
                node->put(bit, new Node());
            }
            node = node->getNext(bit);  // movve to next node
        }

        // after the loop finishes we will be on the last node make its flag
        // true
        node->setFlag();
    }

    int getMax(int n) {
        Node* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (n >> i) & 1;  // like n>>31 & 1 gets us the MSB first so
                                     // MSB -> LSB processing
            int reqBit = bit ^ 1;  // which is the bit complement
            if (node->containsKey(reqBit)) {
                // reqbit exists
                maxNum =
                    maxNum |
                    (1 << i);  // 1 because if reqbit^bit=1 always and we have
                               // to push it i to left side so left shift
                node = node->getNext(reqBit);
            } else {
                node = node->getNext(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* T = new Trie();
        for (int num : nums) {
            T->insert(num);
        }
        sort(nums.begin(), nums.end());
        int ans = 0;

        for (int num : nums) {
            ans = max(ans, T->getMax(num));
        }

        return ans;
    }
};