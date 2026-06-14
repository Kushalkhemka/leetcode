class Solution{
public:
    int ladderLength(const string &startWord, const  string &targetWord,
                         const vector<string> &wordList) {
        unordered_set<string> st;
        for(const string &s:wordList){
            st.insert(s);
        }

        if(st.find(targetWord)==st.end()) return 0;

        queue<pair<string,int>> q;
        q.push({startWord,1});
        //remove startWord if present because otherwise it will be pushed again into queue when a char is transformed from a to z so that char is also included and we will find a match in the set
        if(st.find(startWord)!=st.end()) st.erase(startWord);

        while(!q.empty()){
            //chng the every character from a to z
            string word=q.front().first;
            string original=word;
            int step=q.front().second;
            q.pop();
            for(int i=0;i<word.length();i++){
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(word==targetWord){
                        return step+1;
                    }
                    if(st.find(word)!=st.end()){
                        //it means it exists so remove it and add to queue
                        q.push({word,step+1});
                        st.erase(word);
                    }
                }
                word=original; //so char of original is preserved otherwise it will modify our whole startWord which is wrong
            }
        }
        return 0;
    }
};