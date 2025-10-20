class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //assume the first string to be the common amonst other handle the edge case of only single string in the vector
        string common=strs[0];
        for(int i=1;i<strs.size();i++){
            //initialise the two pointer on common string and ith string and see common part
            int j=0; int k=0; int n1=common.length(); int n2=strs[i].length();
            while(j<n1 && k<n2 && common[j]==strs[i][k]){
                j++; k++;
            }
            common = common.substr(0, k);
        }
        return common;
    }
};