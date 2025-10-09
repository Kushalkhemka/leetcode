class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int s=skill.size(); int m=mana.size();
        vector<long long> done(s+1,0);
        for(int i=0;i<m;i++){
            //for each mana we are iterating
            for(int j=0;j<s;j++){
                //take the max of previous(i) and current (i+1) as the length of done is n+1 size so first element remains 0
                done[j+1]=max(done[j],done[j+1])+skill[j]*mana[i];

            }

            //now fixing it
            for(int j=s-1;j>=0;j--){
                done[j]=done[j+1]-skill[j]*mana[i];
            }
        }
        return done[s];
    }
};