class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0; int j=people.size()-1;
        int count=0; int boat=0;
        while(count<people.size()){
            int temp=people[i]+people[j];
            if(temp<=limit){
                i++;j--;
                count+=2;
                boat++;
            }
            else if(temp>limit){
                count+=1;
                j--;
                boat++;
            }
        }
        return boat;
    }
};