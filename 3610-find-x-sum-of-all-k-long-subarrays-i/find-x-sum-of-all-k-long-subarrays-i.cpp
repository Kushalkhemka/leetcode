#include <vector>
#include <map>
#include <algorithm>
#include <utility>

class Solution {
public:
    static bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first; 
        }
        return a.second > b.second;
    }

    std::vector<int> findXSum(std::vector<int>& nums, int k, int x) {
        if (nums.size() < k) return {};

        std::vector<int> ansV; 
        std::map<int, int> hashmap;
        int n = nums.size();

        for (int i = 0; i < k; i++) {
            hashmap[nums[i]]++;
        }

        int i = 0;
        int j = k - 1;

        while (j < n) {
            std::vector<std::pair<int, int>> freq_vec(hashmap.begin(), hashmap.end());
            std::sort(freq_vec.begin(), freq_vec.end(), cmp);
            
            int current_sum = 0;
            for (int count = 0; count < x && count < freq_vec.size(); ++count) {
                // The number is freq_vec[count].first
                // The frequency is freq_vec[count].second
                current_sum += freq_vec[count].first * freq_vec[count].second;
            }
            ansV.push_back(current_sum);

            // Slide window
            hashmap[nums[i]]--;
            if (hashmap[nums[i]] == 0) {
                hashmap.erase(nums[i]);
            }
            
            i++; 
            j++;
            
            if (j < n) {
                hashmap[nums[j]]++;
            }
        }
        return ansV;
    }
};