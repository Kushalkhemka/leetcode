class Solution {
public:
    unordered_map<int, int> hashfreq;
    unordered_map<int, long long> hashmap; 

    long long solve(vector<int> &power, int idx){
        //we have to solve for the first index first
        long long maxPower=INT_MIN;
        if (idx>=power.size()) return 0; //base case 1 prevents OOB error
        //we need to find the index for the upper bound just less than the target 
        if(hashmap.count(idx)){
            //exists in the hashmap
            return hashmap[idx]; //return the value of the power of that idx
        } 

        //we need to build the memoisation table we are solving from top down approach so make a map or set to store the value      
        maxPower=max(solve(power,idx+1),(long long)power[idx]*(long long)hashfreq[power[idx]]+solve(power,upperBound(power,power[idx] - 3)));
       return hashmap[idx] = maxPower;
    }
    int upperBound(vector<int>& power,int target){
        int lo=0; int hi=power.size()-1;
        int ans=power.size();
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(power[mid]<=target){
                ans=mid;
                hi=mid-1;
                
            }
            else{
               lo=mid+1;
            }
        }
        return ans;
    }
    long long maximumTotalDamage(vector<int>& power) {

        if (power.empty()) return 0;
        hashfreq.clear();
        hashmap.clear();
        for (int p : power) {
            hashfreq[p]++; //count the freq
        }
        power.clear();
        for(auto &[val,freq]:hashfreq){
            //just overwrite the power array i think to save the space and pass the length
            power.push_back(val);
        }
        
        //k is the new length of the power array of unique elements overwritten needs to pass as arg
        sort(power.rbegin(),power.rend());
        return solve(power, 0);

    }
};