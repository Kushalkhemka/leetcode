class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
         if (words.size() <= 1) { // CHANGED: Handle edge case of 0 or 1 words.
            return words;
        }
        //start the i from 1
        
        int i=1;
        while(i<words.size()){
            unordered_map <char,int> freq1;
            //first wale ka bana lo i-1
            for(char c:words[i-1]){
                freq1[c]++;
            }

            //now make of second which is of ith position
            unordered_map <char,int> freq2;
            for(char c:words[i]){
                freq2[c]++;
            }

            //now check if the freq map are equal or not
            if(freq1==freq2){
                //if yes then remove the ith word
                words.erase(words.begin() + i);
            }
            else{
                i++;
            }
        }
        return words;
    
    }
};