#include <vector>
#include <string>
#include <algorithm>
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if (words.empty()) {
            return {};
        }

        vector<string> result;
        result.push_back(words[0]); // The first word is always kept.

        for (int i = 1; i < words.size(); ++i) {
            // Create sorted versions of the current word and the last kept word.
            string current_word_sorted = words[i];
            string last_kept_word_sorted = result.back();
            
            sort(current_word_sorted.begin(), current_word_sorted.end());
            sort(last_kept_word_sorted.begin(), last_kept_word_sorted.end());

            // If the sorted versions are different, they are not anagrams.
            if (current_word_sorted != last_kept_word_sorted) {
                result.push_back(words[i]); // Keep the current word.
            }
        }
        return result;
    }
};