class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,bool> mp;
        int cnt=0; 
        for(auto x:word){
            if(mp.find(x)!=mp.end()){
                //exists
                continue;
            }
            else if(mp.find(char(int(x)+32))!=mp.end()){
                mp[char(int(x)+32)]=true;
            }
            else if(mp.find(char(int(x)-32))!=mp.end()){
                mp[char(int(x)-32)]=true;
            }
            else{
                mp[x]=false;
            }
        }

        for(auto x:mp){
            if(x.second==true){
                cnt++;
            }
        }
        return cnt;
    }
};