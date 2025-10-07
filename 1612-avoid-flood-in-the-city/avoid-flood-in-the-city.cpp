class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        // CHANGED: The map must store the DAY the lake was filled. This is the key fix.
        unordered_map<int, int> full_lakes; 
        set<int> sunny_days;
        int n = rains.size();
        
        // CHANGED: Initialize the answer vector to prevent out-of-bounds errors.
        vector<int> ans(n); 

        for (int i = 0; i < n; ++i) { // CHANGED: A for-loop is cleaner and safer.
            if (rains[i] > 0) {
                ans[i] = -1;
                int lake = rains[i];

                if (full_lakes.find(lake) == full_lakes.end()) {
                    // This lake is not full. Mark it as full on the current day.
                    full_lakes[lake] = i;
                } else {
                    // CRISIS: This lake is already full.
                    // Get the day it was last filled.
                    int last_fill_day = full_lakes[lake];
                    
                    // CHANGED: Instead of taking the beginning, find the first sunny day *after* the last fill day.
                    auto it = sunny_days.upper_bound(last_fill_day);
                    
                    if (it == sunny_days.end()) {
                        // No valid sunny day found. Flood is unavoidable.
                        return {};
                    }
                    
                    int day_to_use = *it;
                    ans[day_to_use] = lake; // Use this sunny day.
                    sunny_days.erase(it);   // Remove the used sunny day.
                    
                    full_lakes[lake] = i; // The lake becomes full again today.
                }
            } else {
                // Sunny day. Add the index to our set of opportunities.
                sunny_days.insert(i);
                ans[i] = 1; // Set a default value.
            }
        }
        return ans;
    }
};