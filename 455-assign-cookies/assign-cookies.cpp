class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
       int i=0;int j=0;
        int ng=g.size();int ns=s.size();
        while(i<ng && j<ns){
            if(s[j]>=g[i]) {j++;i++;}
            else j++;
        }
        return i;
    }
};