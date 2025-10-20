class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        //simple shit
        int X=0;
        for(string s:operations){
            int i=0;
            while(true){
                if(s[i]=='-'){
                    X--; 
                    break;
                }
                else if(s[i]=='+'){
                    X++; break;
                }
                else{
                    i++;
                }
            }
        }
        return X;
    }
};