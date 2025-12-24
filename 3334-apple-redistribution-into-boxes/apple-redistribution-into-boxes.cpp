class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(),greater<int>());
        int currSum=0;
        for(int a:apple){
            currSum+=a;
        }
        int currCap=0; int j=0;
        while(currSum>currCap){
            currCap+=capacity[j];
            j++;
        }
        return j;
    }
};