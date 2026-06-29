/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
   
  

        vector<int> candidates;
        ///first go for outdegree
        for(int i=0;i<n;i++){
            int flg=0;
            for(int j=0;j<n;j++){
                if(knows(i,j)&& i!=j) {flg=1;break;}
            }
            if(!flg) candidates.push_back(i);
        }

        for(auto&c:candidates){
            int flg=0;
            for(int i=0; i<n;i++){
                if(!knows(i,c) && i!=c){
                    flg=1; break;
                }
            }
            if(!flg) return c;
        }
        return -1;

    }
};