class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        vector<int> ans;

        int n = a.size();
        for (int i = 0; i < n; i++) {
            if (s.empty()) {
                s.push(a[i]);
                continue;
            }
            // pushing negative collide not the positive as (negative first,
            // then positive move far away from each other)
            if (a[i] < 0) {
                while (!s.empty() &&s.top()>0  && s.top() < abs(a[i])) {
                    s.pop();
                }
                if (s.empty() ||s.top()<0 )
                    s.push(a[i]);
                else if(s.top()==abs(a[i])) s.pop(); 
            } else {
                s.push(a[i]);
            }

           
        }
         while (!s.empty()) {
                ans.push_back(s.top());
                s.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
    }
};