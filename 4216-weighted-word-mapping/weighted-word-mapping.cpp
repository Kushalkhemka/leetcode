class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        char x='a';
        char y='z';
        for(string w:words){
            //w is string
            int sum=0;
            for(char c:w){
                sum+=weights[int(c-x)];
            }
            sum=sum%26;
            
            ans.push_back(char(y-sum));
        }
        return ans;
    }
};