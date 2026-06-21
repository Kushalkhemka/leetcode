class Solution {
public:
    int calPoints(vector<string>& operations) {
        int score = 0;
        stack<int> s;
        for (auto& c : operations) {
            if (c == "C") {
                score -= s.top();
                s.pop();
            } else if (c == "D") {
                int temp = s.top() * 2;
                score += temp;
                s.push(temp);
            } else if (c == "+") {
                int temp = s.top();
                s.pop();
                int temp2 = s.top();
                s.push(temp);
                score+=temp+temp2;
                s.push(temp+temp2);
            }
            else{
                int temp = stoi(c);
                s.push(temp);
                score+=temp;
            }
        }
        return score;
    }
};