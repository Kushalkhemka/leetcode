class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //bete just like two sum do this shit
        

        //look for the x+1 if exist in the hashmap;
        int n=nums.size(); unordered_map<int,int> hashmap; int res=0;
        if(n==0) return 0;
        for(int j=0;j<n;j++){
            hashmap.insert({nums[j],j});
        }
        //hashmap is builded
        //second pass
        int k=0;
        for(auto const&[i,idx]:hashmap){
            if(hashmap.find(i-1)==hashmap.end()){ //it is indeeed starting point
                //check if curent element i in hashmap is starting point or not
                int length=1;
                int k=1;
                while(true){
                    //keep checking for i+1 numbers exist in or not 
                    if(hashmap.find(i+k)!=hashmap.end()){
                        length++; //increase length if i+1 number exists if not exists reset the length
                        k++;
                    }
                    else{
                        res=max(length,res);
                        
                        break;
                    }
                }
            }

        }
        //hme hashmap me iterate krna h and check check ki vo starting point h ya nahi if starting point then check if complement exist in a loop condition keep checking and if starting point nahi h 
        return res;
    }
};