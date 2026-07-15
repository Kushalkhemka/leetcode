class Solution {
public:
    string addStrings(string& num1, string& num2) {
        // start from the backside of both

        int n1 = num1.size();
        int n2 = num2.size();

        // jo bi badi string h usme kro traverse
        int carry = 0;
        int sum = 0;

        int i = n1 - 1;
        int j = n2 - 1;
        string ans;
        while (i >= 0 && j >= 0) {
            // now traverse
            int result = (num1[i] - '0') + (num2[j] - '0') + carry;
            sum = result % 10;
            carry = result / 10;
            ans.push_back(sum + '0');
            i--;
            j--;
        }

        // some string remains
        while (i >= 0) {
            int result = (num1[i] - '0') + carry;
            sum = result % 10;
            carry = result / 10;
            ans.push_back(sum + '0');
            i--;
        }

        while (j >= 0) {
            int result = (num2[j] - '0') + carry;
            sum = result % 10;
            carry = result / 10;
            ans.push_back(sum + '0');
            j--;
        }

        if (carry != 0)
            ans.push_back(carry + '0');

        reverse(ans.begin(), ans.end());
        return ans;
    }
};