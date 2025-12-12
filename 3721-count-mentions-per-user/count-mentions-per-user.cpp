class Solution {
public:
    static bool cmp(vector<string>& e1, vector<string>& e2) {
        int t1 = stoi(e1[1]);
        int t2 = stoi(e2[1]);

        if (t1 < t2)
            return true; // earlier timestamp comes first
        if (t1 > t2)
            return false; // later timestamp comes after

        //at this point, t1 == t2, so we enforce type priority
        // OFFLINE must be processed before MESSAGE at the same timestamp

        if (e1[0] == e2[0]) {
            // ordering (std::sort will consider them equivalent; relative order
            // doesn't matter)
            return false;
        }

        else if (e1[0] == "OFFLINE" && e2[0] == "MESSAGE") {
            return true;
        }

        else if (e1[0] == "MESSAGE" && e2[0] == "OFFLINE") {
            return false;
        } else
            return false; // dummy return unreachable code
    }
    vector<int> countMentions(int numberOfUsers,
                              vector<vector<string>>& events) {
        vector<int> offlineUntil(
            numberOfUsers,
            0); // timestamp start from 1 so at 0 means all are online initially
        vector<int> mentions(numberOfUsers,
                             0); // to keep track of mentions of each user

        // sorting by timestamp
        sort(events.begin(), events.end(), cmp);
        int globalIncremetToAll = 0;

        // let's start looping for each event
        for (auto& e : events) {
            string messageType = e[0];
            int timestamp = stoi(e[1]);

            if (messageType == "OFFLINE") {
                int id = stoi(e[2]);
                offlineUntil[id] = timestamp + 60;
            } else if (messageType == "MESSAGE") {
                // also check for the submessage type
                string payload = e[2];
                if (payload == "ALL")
                    globalIncremetToAll++;
                else if (payload == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (timestamp >= offlineUntil[i]) {
                            // means it is ONLINE
                            mentions[i]++;
                        }
                    }
                } else {
                    istringstream iss(payload);
                    string token;
                    while (iss >> token) {
                        int id = stoi(token.substr(2));
                        mentions[id]++;
                    }
                }
            }
        }

        for (int i = 0; i < numberOfUsers; i++) {
            mentions[i] = mentions[i] + globalIncremetToAll;
        }

        return mentions;
    }
};