class Solution {
public:
    int minPartitions(const string &n) {
        
        int max=INT_MIN;
        for(char c:n){
            if(c-'0'>max) max=c-'0';
        }

        return max;
        
    }
};