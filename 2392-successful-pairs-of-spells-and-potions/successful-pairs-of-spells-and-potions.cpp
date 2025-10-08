class Solution {
public:
    int lowerBound(vector<int>& portions, long long target) {
        int n = portions.size();
        int lo = 0;
        int hi = n - 1;
        int ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (portions[mid] >= target) {
                ans = mid; // potentional answer
                // check on left half for more
                hi = mid - 1;

            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int s = spells.size();
        int p = potions.size();
        vector<int> ans; 
        sort(potions.begin(), potions.end()); // sorting the portion array
        // iterating the spells array
        for (int i = 0; i < s; i++) {
            // for each i we need to do the lower bound search and then subract
            // the index from the size of the potions array
            long long target=(long long)ceil((double)success / spells[i]);
            int lowerBoundIdx=lowerBound(potions,target);
            int NumberOfPotions=p-lowerBoundIdx;
            
            ans.emplace_back(NumberOfPotions);
            cout<<lowerBoundIdx<<endl;
        }
        return ans;
    }
};