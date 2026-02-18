class Solution {
public:
    bool isAllOnes(unsigned int r) { return r != 0 && ((r & (r + 1)) == 0); }
    bool hasAlternatingBits(int n) {
        int r = n ^ (n >> 1);
        return isAllOnes(r);
    }
};