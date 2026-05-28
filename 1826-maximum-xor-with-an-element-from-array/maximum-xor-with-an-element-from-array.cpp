
class Node {
   public:
    Node* links[2];

    Node() {
        for (int i = 0; i < 2; i++) {
            links[i] = nullptr;
        }
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
        static bool cmp(const vector<int> &a,const vector<int> &b){
            return a[1] < b[1];
        }
    	vector<int> maximizeXor(vector<int>& nums, vector<vector<int> >& queries) {
            Trie* T=new Trie();
            vector<vector<int>> offline;
            vector<int> ans(queries.size());
            for(int i=0;i<queries.size();i++){
                offline.push_back({queries[i][0], queries[i][1], i});
            }
            sort(offline.begin(), offline.end(), cmp);
            sort(nums.begin(),nums.end());
            int j=0;
            for(int i=0; i<offline.size();i++){
                //processing every query one by one
                while(j < nums.size() && nums[j]<=offline[i][1]){
                    T->insert(nums[j]);
                    j++;
                }
                if(j==0) ans[offline[i][2]] =-1;
                else ans[offline[i][2]]=(T->getMax(offline[i][0]));
            }
            return ans;
    	}
};
