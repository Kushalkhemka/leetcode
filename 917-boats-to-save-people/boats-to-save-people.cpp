class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0, j = people.size()-1;
        int boat=0;
        while (i <= j){
            int temp = people[i]+people[j];
            if (temp <= limit){
                i++;
            }
            j--;
            boat++;
        }
        return boat;
    }
};//auto hak=atexit([](){ofstream("display_runtime.txt")<<"0";});