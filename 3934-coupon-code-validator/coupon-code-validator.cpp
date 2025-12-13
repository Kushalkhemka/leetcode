class Solution {
public:
    static int pr(const string &b) {
        if (b == "electronics") return 0;
        if (b == "grocery") return 1;
        if (b == "pharmacy") return 2;
        return 3; // restaurant
    }

    static bool cmp(const pair<string, string> &a, const pair<string, string> &b) {
        int pa = pr(a.first), pb = pr(b.first);
        if (pa != pb) return pa < pb;
        return a.second < b.second;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = (int)code.size();
        vector<pair<string, string>> good;

        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            if (code[i].empty()) continue;

            bool ok = true;
            for (unsigned char c : code[i]) {
                if (!(isalnum(c) || c == '_')) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            if (!(businessLine[i] == "electronics" || businessLine[i] == "grocery" ||
                  businessLine[i] == "pharmacy"   || businessLine[i] == "restaurant")) {
                continue;
            }

            good.push_back({businessLine[i], code[i]});
        }

        sort(good.begin(), good.end(), cmp);

        vector<string> ans;
        ans.reserve(good.size());
        for (auto &p : good) ans.push_back(p.second);

        return ans;
    }
};
