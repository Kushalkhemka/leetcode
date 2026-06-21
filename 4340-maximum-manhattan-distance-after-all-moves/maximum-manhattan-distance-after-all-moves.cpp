class Solution {
public:
    int maxDistance(const string &moves) {
        int x=0;int y=0; int count=0;
        for( auto &c:moves){
            if(c=='L') x-=1;
            else if(c=='D') y-=1;
            else if(c=='U') y+=1;
            else if(c=='R') x+=1;
            else count++;
        }
        return abs(x)+abs(y)+count;
    }
};